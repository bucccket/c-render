#pragma once

#include "graphic.h"

typedef struct sprite_{
  short formatVersion;
  const char* spriteName;
  short frameCount;
  short x,y;
  graphic *graphics[];
}sprite;

extern const struct SpriteClass {
	sprite (*new)(const char* spriteName);
} sprite_;
