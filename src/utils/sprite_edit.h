#pragma once

#include <sys/ioctl.h>
#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "keyboard.h"
#include "../filesystem/content_loader.h"
#include "../render_pipeline/char_render.h"

void spriteEdit();
void drawBorder(int width, int height);
void drawBox(int x, int y,char **ptr);