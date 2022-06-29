#include "graphic.h"

static void freeBuffer(struct graphic_ *this)
{
  if (this->data && this->mask)
  {
    for (int i = 0; i <= this->height; i++) // memory needs 1 elemsiz extra ?
    {
      free(this->data[i]);
      free(this->mask[i]);
    }
  }
  free(this->mask);
  free(this->data);
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