#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "graphic.h"

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
