#include "sprite.h"

static struct sprite_* new(const char* name) {
  sprite* sprite_ptr = (sprite*)calloc(4, sizeof(sprite_));
  *sprite_ptr = (struct sprite_){.spriteName=name};
  return sprite_ptr;
}

const struct SpriteClass sprite_={.new=&new};
