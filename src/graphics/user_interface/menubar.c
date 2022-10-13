#include "menubar.h"

static void destroy(menubar *this)
{
    if (this->menuItems)
    {
        this->menuItems->pfVectorFree(this->menuItems);
        free(this->menuItems);
    }
    free(this);
}

static void render(menubar *this)
{
    int x, y = 0;

    if (this->x + this->width >= this->window->width || this->y + this->height >= this->window->height)
    {
        return;
    }

    int vLine = W_VLINE;
    int hLine = W_HLINE;
    int ulCorner = W_ULCORNER;
    int urCorner = W_URCORNER;
    int llCorner = W_LLCORNER;
    int lrCorner = W_LRCORNER;

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

    int offx = 1;
    for (int i = 0; i < this->menuItems->pfVectorTotal(this->menuItems); i++)
    {
        char *item = (char *)this->menuItems->pfVectorGet(this->menuItems, i);
        mvaddch(this->y + 1, this->x + offx++, ' ');
        mvprintw(this->y + 1, this->x + offx, " %s | ", item + 1);
        attron(A_UNDERLINE);
        mvaddch(this->y + 1, this->x + offx, item[0]);
        attroff(A_UNDERLINE);
        offx += strlen(item) + 2;
        mvaddch(this->y, this->x + offx - 1, ACS_TTEE);
        mvaddch(this->y + 2, this->x + offx - 1, ACS_BTEE);
    }
}

static menubar *new (struct window_ *window, int layoutRule)
{
    menubar *menubar_ptr = (menubar *)malloc(sizeof(menubar));

    vector *v = sVector.new();
    v->pfVectorAdd(v, "Menu");
    v->pfVectorAdd(v, "Edit");
    v->pfVectorAdd(v, "View");

    *menubar_ptr = (menubar){
        .window = window,
        .x = 1,
        .y = 1,
        .width = window->width - 2,
        .height = 3,
        .layoutRule = layoutRule,
        .menuItems = v,
        .render = &render,
        .destroy = &destroy};
    return menubar_ptr;
}

const struct MenuBarClass menubar_ = {.new = &new};
