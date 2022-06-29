#include "buffered_reader.h"

static byte readUint8(buffer *this)
{
  return (byte)this->data[this->offset++];
}

static word readUint16(buffer *this)
{
  return (unsigned short)((byte)this->data[this->offset++] << 0 |
                          (byte)this->data[this->offset++] << 8);
}

static dword readUint32(buffer *this)
{
  return (unsigned int)((byte)this->data[this->offset++] << 0 |
                        (byte)this->data[this->offset++] << 8 |
                        (byte)this->data[this->offset++] << 16 |
                        (byte)this->data[this->offset++] << 24);
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
    fprintf(stderr,"Error: could not allocate memory for string\n");
    return NULL;
  }
  memcpy(str, this->data + this->offset - size, size - 1);
  return str;
}

static void *freeBuffer(buffer *this)
{
  if(this->data)
  {
    free(this->data);
  }
  free(this);
}

static buffer *new (FILE *data)
{
  buffer *buffer_struct = (buffer *)malloc(sizeof(buffer));
  *buffer_struct = (buffer){.data = readFile(data), .size = getFileSize(data), .offset = 0, .readUint8 = &readUint8, .readUint16 = &readUint16, .readUint32 = &readUint32, .readString = &readString, .freeBuffer = &freeBuffer};
  return buffer_struct;
}

const struct BufferClass buffer_ = {.new = &new};

off_t getFileSize(FILE *f)
{
  if (fseeko(f, 0, SEEK_END) != 0)
  {
    fprintf(stderr,"reading error SEEK_END\n");
    return 0;
  }
  off_t size = ftello(f);
  if (fseeko(f, 0, SEEK_SET) != 0)
  {
    fprintf(stderr,"reading error SEEK_SET\n");
    return 0;
  }
  return size;
}

//TODO: unify bytestream type with all buffer fields
bytestream readFile(FILE *f) 
{
  off_t size = getFileSize(f);

  rewind(f);
  bytestream data = (bytestream)calloc(size, sizeof(char));
  if (!data)
  {
    fprintf(stderr,"Filestream malloc error.\n");
    return NULL;
  }
  fread(data, size, 1, f);
  fclose(f);
  return data;
}
