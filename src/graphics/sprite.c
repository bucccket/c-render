#include "sprite.h"

static struct sprite_ new(const char* name) {
  return (struct sprite_){.spriteName=name};
}
const struct SpriteClass sprite_={.new=&new};
