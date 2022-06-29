#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct graphic_
{
  void (*freeBuffer)(struct graphic_ *this);

  int sectionSize;
  char *name;
  short x, y;
  short width, height;
  char **data;
  char **mask;
} graphic;

extern const struct GraphicClass
{
  graphic *(*new)();
} graphic_;
