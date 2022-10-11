#include "graphic.h"

/**
 * @brief free graphic struct and members
 *
 * @param this
 */
static void freeBuffer(graphic *this)
{
  if (this->data && this->mask)
  {
    for (int i = 0; i <= this->height; i++)
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

static graphic *new ()
{
  graphic *graphic_ptr = (graphic *)malloc(sizeof(graphic));
  *graphic_ptr = (graphic){.freeBuffer = &freeBuffer};
  return graphic_ptr;
}

const struct GraphicClass graphic_ = {.new = &new};