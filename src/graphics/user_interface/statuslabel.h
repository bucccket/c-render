#pragma once

#include <stdlib.h>

#include "window.h"
#include "ui_utils.h"

typedef struct statuslabel_
{
    struct window_ *window;
    char *content;
    void (*render)(struct statuslabel_ *this);
    void (*destroy)(struct statuslabel_ *this);
} statuslabel;

extern const struct StatuslabelClass
{
    statuslabel *(*new)(struct window_ *window, char *content);
} statuslabel_;
