#include "graphic.h"

static void freeBuffer(struct graphic_ *this)
{
  free(this->data);
  free(this->mask);
  free(this->name);
  free(this);
}

static struct graphic_ *new ()
{
  graphic *graphic_ptr = (graphic *)malloc(sizeof(graphic));
  *graphic_ptr = (struct graphic_){.freeBuffer = &freeBuffer};
  return graphic_ptr;
}

const struct GraphicClass graphic_ = {.new = &new};