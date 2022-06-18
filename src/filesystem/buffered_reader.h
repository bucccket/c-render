#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct buffer_{
  int size;
  int offset;
  char* data;
  unsigned char (*readUint8)(struct buffer_ *this);
  unsigned short (*readUint16)(struct buffer_ *this);
  unsigned int (*readUint32)(struct buffer_ *this);
  unsigned long long int (*readUint64)(struct buffer_ *this);
  const char* (*readString)(struct buffer_ *this); //TODO: delimited by 0 or as struct.
};

extern const struct BufferClass {
	struct buffer_ (*new)(char* data);
} buffer_;

typedef struct buffer_ buffer;


