#pragma once

#include <stdarg.h>
#include <stdlib.h>

#include "window.h"

#define COMPOSITE_FLAG_EXTEND_V 0x1
#define COMPOSITE_FLAG_EXTEND_H 0x2
#define COMPOSITE_FLAG_CENTER 0x4

// NOTE: because of the way the codependency of window and composite I need to reference the struct instead of the typedef
typedef struct composite_
{
    struct window_ *window;
    char *compositeName;
    int x, y;
    int width, height;
    int compositeRule; // flags for composite rule
    void (*render)(struct composite_ *this);
    void (*destroy)(struct composite_ *this);
} composite;

extern const struct CompositeClass
{
    composite *(*new)(struct window_ *window, char *compositeName, int x, int y, int width, int height, int compositeRule);

} composite_;
