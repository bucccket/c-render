#include "graphic.h"

static struct graphic_* new(void) {
  graphic* graphic_ptr = (graphic*)calloc(1, sizeof(graphic_));
  *graphic_ptr = (struct graphic_){};
  return graphic_ptr;
}

const struct GraphicClass graphic_={.new=&new};
