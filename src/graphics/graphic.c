#include "graphic.h"

static struct graphic_ new(void) {
  return (struct graphic_){};
}
const struct GraphicClass graphic_={.new=&new};
