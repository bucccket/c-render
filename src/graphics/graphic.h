#pragma once

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief buffer struct contains site, name, relative bounds, graphic and mask data
 *
 */
typedef struct graphic_
{
  int sectionSize;
  char *name;
  short x, y;
  short width, height;
  char **data;
  char **mask;

  void (*freeBuffer)(struct graphic_ *this); /** @brief free buffer (self) and members @param this */
} graphic;

extern const struct GraphicClass
{
  graphic *(*new)();
} graphic_;
