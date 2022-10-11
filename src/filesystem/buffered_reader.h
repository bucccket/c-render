#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define FS_OK 0
#define FS_FILE_ERROR 1
#define FS_HEADER_ERROR 2
#define FS_PARSE_ERROR 3

/**
 * @brief buffer struct contains size, position and filestream
 *
 */
typedef struct buffer_
{
  unsigned char (*readUint8)(struct buffer_ *this);   /** @brief read 8 bytes @param this @return byte */
  unsigned short (*readUint16)(struct buffer_ *this); /** @brief read 16 bytes @param this @return word */
  unsigned int (*readUint32)(struct buffer_ *this);   /** @brief read 32 bytes @param this  @return dword */
  char *(*readString)(struct buffer_ *this);          /** @brief read NULL delimited string @param this @return char* */
  void (*freeBuffer)(struct buffer_ *this);           /** @brief free buffer (self) and members @param this */

  int size;            /** @brief size of buffer */
  int offset;          /** @brief offset of buffer */
  unsigned char *data; /** @brief data of buffer */
} buffer;

extern const struct BufferClass
{
  buffer *(*new)(FILE *data);
} buffer_;

unsigned char *readFile(FILE *f);
off_t getFileSize(FILE *f);
