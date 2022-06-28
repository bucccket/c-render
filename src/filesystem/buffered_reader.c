#include "buffered_reader.h"

static byte readUint8(struct buffer_ *this)
{
  return (byte)this->data[this->offset++];
}

static word readUint16(struct buffer_ *this)
{
  return (unsigned short)((byte)this->data[this->offset++] << 0 |
                          (byte)this->data[this->offset++] << 8);
}

static dword readUint32(struct buffer_ *this)
{
  return (unsigned int)((byte)this->data[this->offset++] << 0 |
                        (byte)this->data[this->offset++] << 8 |
                        (byte)this->data[this->offset++] << 16 |
                        (byte)this->data[this->offset++] << 24);
}

static const char *readString(struct buffer_ *this) // \0 delimted strings
{
  int size = 0;
  do
  {
    size++;
  } while (this->data[this->offset++] != 0 && this->offset < this->size);
  char *str = (char *)calloc(size, sizeof(char));
  if (!str)
  {
    return NULL;
  }
  memcpy(str,this->data + this->offset - size, size-1);
  return str;
}

static struct buffer_ *new (FILE *data)
{
  buffer *buffer_struct = (buffer *)malloc(sizeof(buffer));
  *buffer_struct = (struct buffer_){.data = readFile(data), .size = getFileSize(data), .offset = 0, .readUint8 = &readUint8, .readUint16 = &readUint16, .readUint32 = &readUint32, .readString = &readString};
  return buffer_struct;
}

static void *freeBuffer(struct buffer_ *this)
{
  free(this->data);
}

const struct BufferClass buffer_ = {.new = &new};

off_t getFileSize(FILE *f)
{
  if (fseeko(f, 0, SEEK_END) != 0)
  {
    printf("reading error SEEK_END\n");
    return 0;
  }
  off_t size = ftello(f);
  if (fseeko(f, 0, SEEK_SET) != 0)
  {
    printf("reading error SEEK_SET\n");
    return 0;
  }
  return size;
}

bytestream readFile(FILE *f)
{

  // getting file size by iterating file.

  off_t size = getFileSize(f);

  // rewind  file offset
  rewind(f);
  bytestream data = (bytestream)calloc(size ,sizeof(char));
  if (!data)
  {
    printf("malloc error.\n");
    return NULL;
  }
  fread(data, size, 1, f);
  fclose(f);
  return data;
}
