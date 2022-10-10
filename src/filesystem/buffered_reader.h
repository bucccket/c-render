#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define FS_OK 0
#define FS_ERR_READ 1

typedef unsigned char *bytestream; // byte stream
typedef unsigned char byte;        // 8 bit
typedef unsigned short word;       // 16 bit
typedef unsigned int dword;        // 32 bit

/**
 * @brief buffer struct contains size, position and filestream
 *
 */
typedef struct buffer_
{
  byte (*readUint8)(struct buffer_ *this);   /** @brief read 8 bytes @param this @return byte */
  word (*readUint16)(struct buffer_ *this);  /** @brief read 16 bytes @param this @return word */
  dword (*readUint32)(struct buffer_ *this); /** @brief read 32 bytes @param this  @return dword */
  char *(*readString)(struct buffer_ *this); /** @brief read NULL delimited string @param this @return char* */
  void (*freeBuffer)(struct buffer_ *this);  /** @brief free buffer (self) and members @param this */

  int size;        /** @brief size of buffer */
  int offset;      /** @brief offset of buffer */
  bytestream data; /** @brief data of buffer */
} buffer;

extern const struct BufferClass
{
  buffer *(*new)(FILE *data);
} buffer_;

bytestream readFile(FILE *f);
off_t getFileSize(FILE *f);
