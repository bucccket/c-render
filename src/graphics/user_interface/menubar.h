#pragma once

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "window.h"
#include "ui_utils.h"
#include "../../types/vector.h"

#define LAYOUT_FLAG_TOP 0x1
#define LAYOUT_FLAG_BOTTOM 0x2

typedef struct menubar_
{
    struct window_ *window;
    int x, y;
    int width, height;
    int layoutRule; // flags for composite rule
    vector* menuItems;
    void (*render)(struct menubar_ *this);
    void (*destroy)(struct menubar_ *this);
} menubar;

extern const struct MenuBarClass
{
    menubar *(*new)(struct window_ *window, int layoutRule);
} menubar_;
