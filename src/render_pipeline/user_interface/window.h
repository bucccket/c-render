#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "composite.h"

typedef struct window_
{
  int width;
  int height;
  int xCell;
  int yCell;
  char *title;
  int compositesCount;
  struct composite_ **composites;
  void (*addComposite)(struct window_ *this, struct composite_ *composite);
  void (*render)(struct window_ *this);
  void (*resize)(struct window_ *this, int width, int height);
  void (*destroy)(struct window_ *this);
} window;

extern const struct WindowClass
{
  window *(*new)(int width, int height, int xCell, int yCell, char *title);
} window_;