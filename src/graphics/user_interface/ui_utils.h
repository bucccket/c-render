#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "menubar.h"
#include "composite.h"
#include "statuslabel.h"
#include "label.h"

#define W_VLINE ACS_VLINE
#define W_HLINE ACS_HLINE
#define W_ULCORNER ACS_ULCORNER
#define W_URCORNER ACS_URCORNER
#define W_LLCORNER ACS_LLCORNER
#define W_LRCORNER ACS_LRCORNER

bool checkFlagAt(unsigned int flag, unsigned int bitindex);

typedef struct element_
{
    enum
    {
        COMPOSITE,
        MENUBAR,
        STATUSLABEL,
        LABEL
    } type;
    union
    {
        struct composite_ *composite;
        struct menubar_ *menubar;
        struct statuslabel_ *statuslabel;
        struct label_ *label;
    };
} element;
