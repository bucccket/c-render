#include "sprite_edit.h"

void spriteEdit()
{
    int row, col;
    int r_old = 0, c_old = 0;

    keys key;

    char *title = "[SPRITE EDITOR]";
    char *boxTest[] = {"+--------+",
                       "|  test  |",
                       "+--------+",
                       NULL};

    setlocale(LC_CTYPE, "C-UTF-8");
    initscr();
    initKeyboard();
    while (true)
    {
        usleep(1000000 / FPS); // pass over CPU time while frame is paused

        if (keyHandle(&key) != RENDER_CONTINUE)
        {
            break;
        }

        if (!adjustScreen(&row, &col, &r_old, &c_old))
        {
            drawBorder(col, row);
            mvprintw(0, (col - strlen(title)) >> 1, "%s", title);
            drawBox(2, 1, boxTest);
        }
        refresh();
    }
}

void drawBorder(int width, int height)
{
    mvaddch(0, 0, '+');
    mvaddch(0, width - 1, '+');
    mvaddch(height - 1, 0, '+');
    mvaddch(height - 1, width - 1, '+');
    for (int x = 1; x < width - 1; x++)
    {
        mvaddch(0, x, '=');
        mvaddch(height - 1, x, '=');
    }

    for (int y = 1; y < height - 1; y++)
    {
        mvaddch(y, 0, '|');
        mvaddch(y, 1, '|');
        mvaddch(y, width - 1, '|');
        mvaddch(y, width - 2, '|');
    }
}

void drawBox(int x, int y, char **ptr)
{
    int offs = 0;
    while (*ptr != NULL)
    {
        mvprintw(y + offs++, x, *ptr++);
    }
}