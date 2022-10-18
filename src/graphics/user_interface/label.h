#pragma once

#include <stdlib.h>
#include <stdbool.h>

#include "window.h"
#include "ui_utils.h"

#define TEXT_ORIENTATION_LEFT 0x1
#define TEXT_ORIENTATION_RIGHT 0x2
#define TEXT_ORIENTATION_CENTER 0x4

typedef struct label_
{
    struct window_ *window;
    char *content;
    int x, y;
    int width, height; // internal variables
    int textstyle; // flags for text styling
    bool enabled;
    void (*render)(struct label_ *this);
    void (*setText)(struct label_ *this, char *text);
    void (*destroy)(struct label_ *this);
} label;

extern const struct LabelClass
{
    label *(*new)(struct window_ *window, char *content, int x, int y, int textstyle);
} label_;
