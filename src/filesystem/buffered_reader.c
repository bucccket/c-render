#include "buffered_reader.h"

static byte readUint8(buffer *this)
{
  return (byte)this->data[this->offset++];
}

static word readUint16(buffer *this) // do your homework on these
{
  return (unsigned short)((byte)this->data[this->offset++] << 000 |
                          (byte)this->data[this->offset++] << 010);
}

static dword readUint32(buffer *this)
{
  return (unsigned int)((byte)this->data[this->offset++] << 000 |
                        (byte)this->data[this->offset++] << 010 |
                        (byte)this->data[this->offset++] << 020 |
                        (byte)this->data[this->offset++] << 030);
}

static char *readString(buffer *this) // \0 delimted strings
{
  int size = 0;
  do
  {
    size++;
  } while (this->data[this->offset++] != 0 && this->offset < this->size);
  char *str = (char *)calloc(size, sizeof(char));
  if (!str)
  {
    fprintf(stderr, "[ERROR] could not allocate memory for string\n");
    return NULL;
  }
  memcpy(str, this->data + this->offset - size, size - 1);
  return str;
}

static void freeBuffer(buffer *this)
{
  if (this->data)
  {
    free(this->data);
  }
  free(this);
}

static buffer *new (FILE *data)
{
  buffer *buffer_struct = (buffer *)malloc(sizeof(buffer));
  *buffer_struct = (buffer){.data = readFile(data), .size = getFileSize(data), .offset = 0, .readUint8 = &readUint8, .readUint16 = &readUint16, .readUint32 = &readUint32, .readString = &readString, .freeBuffer = &freeBuffer};
  fclose(data);
  return buffer_struct;
}

const struct BufferClass buffer_ = {.new = &new};

off_t getFileSize(FILE *f)
{
  off_t size;

  fseeko(f, 0, SEEK_SET);
  int *header = calloc(1, sizeof(int));
  fread(header, sizeof(unsigned int), 1, f);

  if (*header == 0xDEADBEEF)
  {
    int *szInflate = calloc(1, sizeof(int));
    fread(szInflate, sizeof(unsigned int), 1, f); // uncompressed sz
    size = *szInflate;
    free(szInflate);
  }
  else
  {
    if (fseeko(f, 0, SEEK_END) != 0)
    {
      fprintf(stderr, "[ERROR] reading error SEEK_END\n");
      return 0;
    }
    size = ftello(f);
    if (fseeko(f, 0, SEEK_SET) != 0)
    {
      fprintf(stderr, "[ERROR] reading error SEEK_SET\n");
      return 0;
    }
  }
  free(header);

  return size;
}

bytestream readFile(FILE *f)
{
  off_t size = getFileSize(f);

  rewind(f);
  int *header = calloc(1, sizeof(int));
  uLongf *szInflate = calloc(1, sizeof(int));
  uLongf *szDeflate = calloc(1, sizeof(int));
  bytestream data = (bytestream)calloc(size, sizeof(char));
  if (!data) // I assume we got space for 4 bytes. if not I will not worry HERE
  {
    fprintf(stderr, "[ERROR] could not allocate memory for file\n");
    free(data);
    free(header);
    free(szDeflate);
    free(szInflate);
    return NULL;
  }

  fread(header, sizeof(unsigned int), 1, f);
  printf("header %06X\n", *header);
  switch (*header)
  {
  case 0xBEEFB055:
    // SPRITE -no compression
    printf("[INFO] uncompressed sprite found\n");
    fread(data, size, 1, f);
    break;
  case 0xDEADBEEF:
    // SPRITE -no compression
    printf("[INFO] compressed sprite found\n");
    fread(szInflate, sizeof(unsigned int), 1, f); // uncompressed sz
    fread(szDeflate, sizeof(unsigned int), 1, f); // compressed sz
    char *deflatedStream = (bytestream)calloc(*szDeflate, sizeof(char));
    fread(deflatedStream, size, 1, f);
    data = (char *)realloc(data, *szInflate); // realloc data buffer to fit the infalted data
    switch (uncompress(data, szInflate, deflatedStream, *szDeflate))
    {
    case Z_BUF_ERROR:
      fprintf(stderr, "[ERROR] zlib failed - buffer corrupted or truncated\n");
      goto end_err;
      break;
    case Z_MEM_ERROR:
      fprintf(stderr, "[ERROR] zlib failed - memory ran out or stack smash occured\n");
      goto end_err;
      break;
    case Z_DATA_ERROR:
      fprintf(stderr, "[ERROR] zlib failed - false zlib header\n");
      goto end_err;
      break;
    case Z_OK:
      printf("[INFO] zlib success\n");
      break;
    default:
      printf("[WARN] zlib failed - unknown error code\n");
    end_err:
      free(data);
      free(header);
      free(szDeflate);
      free(szInflate);
      free(deflatedStream);
      return NULL;
    }
    free(deflatedStream);
    break;
  default:
    printf("[WARN] file header unknown\n");
  }

  free(header);
  free(szDeflate);
  free(szInflate);

  return data;
}
