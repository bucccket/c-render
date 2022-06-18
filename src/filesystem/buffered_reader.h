#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char * bytestream;
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;

struct buffer_
{
  int size;
  int offset;
  bytestream data;
  byte (*readUint8)(struct buffer_ *this);
  word (*readUint16)(struct buffer_ *this);
  dword (*readUint32)(struct buffer_ *this);
  const char *(*readString)(struct buffer_ *this); // TODO: range check at beginning of string
};

extern const struct BufferClass
{
  struct buffer_ (*new)(char *data);
} buffer_;

typedef struct buffer_ buffer;