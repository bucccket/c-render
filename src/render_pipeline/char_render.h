#pragma once

#include <sys/ioctl.h>
#include <ncurses.h>                    /* ncurses includes stdio.h */
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../utils/keyboard.h"
#include "../filesystem/content_loader.h"

#define FPS 60

#define MIN_ROW 32
#define MIN_COL 80

#define RENDER_OK 0
#define RENDER_CONTINUE 1
#define RENDER_ERROR_FS 2

#define SCREEN_OK 0 
#define SCREEN_TOO_SMALL 1

int testScreenCentering(void); //testing screen proportions
int adjustScreen(int *row, int *col, int *r_old, int *c_old);
void drawPrimitiveRect(WINDOW *window, char **ptr, int x, int y);
int keyHandle(keys* key);
