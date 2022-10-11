#pragma once

#include "graphic.h"
#include "../utils/stringutils.h"
#include "../filesystem/buffered_reader.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define FS_OK 0
#define FS_FILE_ERROR 1
#define FS_HEADER_ERROR 2
#define FS_PARSE_ERROR 3

typedef struct sprite_
{
  void (*freeBuffer)(struct sprite_ *this);

  int loaded; //boolean
  short formatVersion;
  char *spriteName;
  short frameCount;
  short x, y;
  graphic **graphics;
} sprite;

extern const struct SpriteClass
{
  sprite *(*new)(char *spriteName);
} sprite_;

int loadSprite(sprite *spriteInst);
int parseGraphic(graphic *g, buffer* spriteFile);
int parseData(buffer *spriteFile, graphic *g);
int parseMask(buffer *spriteFile, graphic *g);