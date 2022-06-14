#pragma once

#include <sys/ioctl.h>
#include <ncurses.h>                    /* ncurses includes stdio.h */
#include <string.h>
#include <stdlib.h>
#include "../utils/keyboard.h"

void testScreenCentering(void); //testing screen proportions
void adjustScreen(int *row, int *col, int *r_old, int *c_old);
void drawPrimitiveRect(WINDOW *window, char **ptr);
