#pragma once

#include <stdlib.h>

typedef struct graphic_{
  int sectionSize;
  const char* name;
  //TODO: animation based fags like : has matrix, has move, has offset?
  short x,y;
  short width, height;
  char **data;
  char **mask;
}graphic;

extern const struct GraphicClass {
	graphic* (*new)(void);
} graphic_;
