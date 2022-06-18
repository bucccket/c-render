#include "buffered_reader.h"

static byte readUint8(struct buffer_ *this)
{
  return (byte)this->data[this->offset++];
}

static word readUint16(struct buffer_ *this)
{
  return (unsigned short)((byte)this->data[this->offset++] << 8 |
                          (byte)this->data[this->offset++] << 0);
}

static dword readUint32(struct buffer_ *this)
{
  return (unsigned int)((byte)this->data[this->offset++] << 24 |
                        (byte)this->data[this->offset++] << 16 |
                        (byte)this->data[this->offset++] << 8 |
                        (byte)this->data[this->offset++] << 0);
}

static const char *readString(struct buffer_ *this)
{
  int i = 0;
  do
  {
    i++;
  } while (this->data[this->offset++] != 0);
  char *str = (char *)malloc(i + 1);
  strncpy(str, (char *)this->data + this->offset - i, i);
}

static struct buffer_ new (char *data)
{
  return (struct buffer_){.data = data, .size = strlen(data), .offset = 0, .readUint8 = &readUint8, .readUint16 = &readUint16, .readUint32 = &readUint32, .readString = &readString};
}

const struct BufferClass buffer_ = {.new = &new};
