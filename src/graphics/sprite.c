#include "sprite.h"

static void freeBuffer(sprite *this)
{
  for (int i = 0; i < this->frameCount; i++)
  {
    graphic *g = this->graphics[i];
    g->freeBuffer(g);
  }
  free(this->graphics);
  free(this->spriteName);
  free(this);
}

static sprite *new (char *name)
{
  sprite *sprite_ptr = (sprite *)malloc(sizeof(sprite));
  *sprite_ptr = (sprite){.spriteName = name, .freeBuffer = &freeBuffer};
  return sprite_ptr;
}

const struct SpriteClass sprite_ = {.new = &new};
