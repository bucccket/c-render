#include "sprite.h"

static void freeBuffer(sprite *this)
{
  if(!this->loaded){
    printf("[ERROR] tried freeing a sprite that was not loaded!\n");
  }
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
  char* allocatedSpriteName = calloc(strlen(name) + 1, sizeof(char));
  memmove(allocatedSpriteName, name, strlen(name));
  sprite *sprite_ptr = (sprite *)malloc(sizeof(sprite));
  *sprite_ptr = (sprite){.loaded = 0,.spriteName = allocatedSpriteName, .freeBuffer = &freeBuffer};
  return sprite_ptr;
}

const struct SpriteClass sprite_ = {.new = &new};
