#pragma once

#include <sys/ioctl.h>
#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../utils/keyboard.h"
#include "../filesystem/content_loader.h"

#define FPS 60

#define MIN_COL 80 //width
#define MIN_ROW 24 //height

#define RENDER_OK 0
#define RENDER_CONTINUE 1
#define RENDER_ERROR_FS 2
#define RENDER_ABORT 3

#define SCREEN_OK 0
#define SCREEN_TOO_SMALL 1
#define SCRREN_NO_COLOR 2

int testScreenCentering(void); // testing screen proportions
int adjustScreen(int *row, int *col, int *r_old, int *c_old);
void drawPrimitiveRect(char **data, int lines, int x, int y);

void drawMaskedRect(char **data, char **mask, int width, int height, int x, int y);
void clearMaskedRect(char **mask, int width, int height, int x, int y);
int keyHandle(keys *key);

void testPrintTime();
