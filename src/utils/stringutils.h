#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

char *prepend(const char *prepended, const char *source);
void hexdump(unsigned char *data, size_t size);
void print2dString(char **data, int lines);
void printACS(void);