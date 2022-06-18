#include "buffered_reader.h"

static struct buffer_ new(char* data) {
  return (struct buffer_){.data=data,.size=strlen(data),.offset=0};
}

static unsigned char readUint8(struct buffer_ *this){
  return 1;
}

static unsigned short readUint16(struct buffer_ *this){
  return (unsigned short)(this->data[this->offset++] |
                       this->data[this->offset++] << 8);
}

static unsigned int readUint32(struct buffer_ *this){
  return (unsigned int)(this->data[this->offset++] |
                     this->data[this->offset++] << 8  |
                     this->data[this->offset++] << 16 |
                     this->data[this->offset++] << 24);
}

static unsigned long long int (*readUint64)(struct buffer_ *this);
static const char* (*readString)(struct buffer_ *this);

const struct BufferClass buffer_={.new=&new};
