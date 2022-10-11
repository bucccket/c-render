#include "menubar.h"

static void destroy(menubar *this)
{
    free(this);
}

static void render(menubar *this)
{
    int x, y = 0;

    if (this->x + this->width >= this->window->width || this->y + this->height >= this->window->height)
    {
        return;
    }

    int vLine = ACS_VLINE;
    int hLine = ACS_HLINE;
    int ulCorner = ACS_ULCORNER;
    int urCorner = ACS_URCORNER;
    int llCorner = ACS_LLCORNER;
    int lrCorner = ACS_LRCORNER;

    for (x = 0; x < this->width; x++)
    {
        for (y = 0; y < this->height; y++)
        {
            if (y <= 0 || y >= (this->height - 1))
            {
                mvaddch(y + this->y, x + this->x, hLine);
            }

            if (x <= 0 || x >= (this->width - 1))
            {
                mvaddch(y + this->y, x + this->x, vLine);
                if (y == 0)
                {
                    mvaddch(y + this->y, x + this->x, x == 0 ? ulCorner : urCorner);
                }
                else if (y >= (this->height - 1))
                {
                    mvaddch(y + this->y, x + this->x, x == 0 ? llCorner : lrCorner);
                }
            }
        }
    }
}

static menubar *new (struct window_ *window, int layoutRule)
{
    menubar *menubar_ptr = (menubar *)malloc(sizeof(menubar));
    *menubar_ptr = (menubar){.window = window, .x = 1, .y = 1, .width = window->width-2, .height = 3, .layoutRule = layoutRule, .render = &render, .destroy = &destroy};
    return menubar_ptr;
}

const struct MenuBarClass menubar_ = {.new = &new};
