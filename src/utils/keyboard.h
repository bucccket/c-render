#pragma once

#include <unistd.h>
#include <ncurses.h>

typedef enum keys_{K_NONE,K_W,K_ESC} keys;

void initKeyboard(void);
int KeyPressed();
