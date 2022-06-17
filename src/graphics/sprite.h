#pragma once

#include "graphic.h"

struct sprite_{
  const char* spriteName;
  graphic *graphics[];
};

extern const struct SpriteClass {
	struct sprite_ (*new)(const char* spriteName);
} sprite_;

typedef struct sprite_ sprite;
