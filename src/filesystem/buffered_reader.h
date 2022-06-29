#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FS_OK 0
#define FS_ERR_READ 1

typedef unsigned char *bytestream;
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;

typedef struct buffer_
{
  byte (*readUint8)(struct buffer_ *this);
  word (*readUint16)(struct buffer_ *this);
  dword (*readUint32)(struct buffer_ *this);
  char *(*readString)(struct buffer_ *this); // TODO: range check at beginning of string
  void (*freeBuffer)(struct buffer_ *this);

  int size;
  int offset;
  bytestream data;
} buffer;

extern const struct BufferClass
{
  struct buffer_ *(*new)(FILE *data);
} buffer_;

bytestream readFile(FILE *f);
off_t getFileSize(FILE *f);
