#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "menubar.h"
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
  int menubarsCount;
  struct menubar_ **menubars;
  void (*addComposite)(struct window_ *this, struct composite_ *composite);
  void (*addMenuBar)(struct window_ *this, struct menubar_ *menubar);
  void (*render)(struct window_ *this);
  void (*resize)(struct window_ *this, int width, int height);
  void (*destroy)(struct window_ *this);
} window;

extern const struct WindowClass
{
  window *(*new)(int width, int height, int xCell, int yCell, char *title);
} window_;