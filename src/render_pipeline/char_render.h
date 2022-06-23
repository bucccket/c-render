#pragma once

#include <sys/ioctl.h>
#include <ncurses.h>                    /* ncurses includes stdio.h */
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../utils/keyboard.h"
#include "../filesystem/content_loader.h"

#define RENDER_OK 0
#define RENDER_ERROR_FS 1

int testScreenCentering(void); //testing screen proportions
void adjustScreen(int *row, int *col, int *r_old, int *c_old);
void drawPrimitiveRect(WINDOW *window, char **ptr, int x, int y);
