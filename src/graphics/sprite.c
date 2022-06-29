#include "sprite.h"

static void freeBuffer(struct sprite_ *this)
{
  for (int i = 0; i < this->frameCount; i++)
  {
    graphic *g = this->graphics[i];
    g->freeBuffer(g);
  }
  free(this->spriteName);
  free(this);
}

static struct sprite_ *new (char *name)
{
  sprite *sprite_ptr = (sprite *)malloc(sizeof(sprite));
  *sprite_ptr = (struct sprite_){.spriteName = name, .freeBuffer = &freeBuffer};
  return sprite_ptr;
}

const struct SpriteClass sprite_ = {.new = &new};
