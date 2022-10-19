#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "menubar.h"
#include "composite.h"
#include "ui_utils.h"

typedef struct window_
{
  int width, height;
  int adjusted_width, adjusted_height; // TODO
  int x, y;                            // TODO
  int xCell;
  int yCell;
  char *title;
  int elementsCount;
  struct element_ **elements;
  void (*add)(struct window_ *this, struct element_ *element);
  void (*render)(struct window_ *this);
  void (*resize)(struct window_ *this, int width, int height);
  void (*destroy)(struct window_ *this);
} window;

extern const struct WindowClass
{
  window *(*new)(int width, int height, int xCell, int yCell, char *title);
} window_;
