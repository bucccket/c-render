#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define W_VLINE ACS_VLINE
#define W_HLINE ACS_HLINE
#define W_ULCORNER ACS_ULCORNER
#define W_URCORNER ACS_URCORNER
#define W_LLCORNER ACS_LLCORNER
#define W_LRCORNER ACS_LRCORNER

bool checkFlagAt(unsigned int flag, unsigned int bitindex);
