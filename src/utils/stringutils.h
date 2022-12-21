#pragma once

#ifndef _XOPEN_SOURCE_EXTENDED
# define _XOPEN_SOURCE_EXTENDED 1
#endif

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <curses.h>
#include <stdlib.h>

#ifdef WACS_S1
# define HAVE_WIDE 1
#else
# define HAVE_WIDE 0
#endif

#include <locale.h>

#if HAVE_WIDE
# include <wchar.h>
#endif

#if defined(PDCURSES) && !defined(XCURSES)
# define HAVE_RESIZE 1
#else
# define HAVE_RESIZE 0
#endif

#ifdef A_COLOR
# define HAVE_COLOR 1
#else
# define HAVE_COLOR 0
#endif

#ifdef PDCURSES
# define HAVE_CLIPBOARD 1
#else
# define HAVE_CLIPBOARD 0
#endif

char *prepend(const char *prepended, const char *source);
void hexdump(unsigned char *data, size_t size);
void print2dString(char **data, int lines);
void printACS(void);
void inputTest(WINDOW *);
void scrollTest(WINDOW *);
void introTest(WINDOW *);
int initTest(WINDOW **);
void outputTest(WINDOW *);
void padTest(WINDOW *);
void acsTest(WINDOW *);
void attrTest(WINDOW *);
#if HAVE_COLOR
void colorTest(WINDOW *);
#endif
#if HAVE_RESIZE
void resizeTest(WINDOW *);
#endif
#if HAVE_CLIPBOARD
void clipboardTest(WINDOW *);
#endif
#if HAVE_WIDE
void wideTest(WINDOW *);
#endif
void display_menu(int, int);


struct commands
{
    const char *text;
    void (*function)(WINDOW *);
};

typedef struct commands COMMAND;

#define MAX_OPTIONS (7 + HAVE_COLOR + HAVE_RESIZE + HAVE_CLIPBOARD + HAVE_WIDE)

COMMAND command[MAX_OPTIONS] =
{
    {"Intro Test", introTest},
    {"Pad Test", padTest},
#if HAVE_RESIZE
    {"Resize Test", resizeTest},
#endif
    {"Scroll Test", scrollTest},
    {"Input Test", inputTest},
    {"Output Test", outputTest},
    {"ACS Test", acsTest},
    {"Attrib Test", attrTest},
#if HAVE_COLOR
    {"Color Test", colorTest},
#endif
#if HAVE_CLIPBOARD
    {"Clipboard Test", clipboardTest},
#endif
#if HAVE_WIDE
    {"Wide Input", wideTest}
#endif
};

int width, height;
