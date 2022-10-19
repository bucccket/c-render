#include "composite.h"

static void destroy(composite *this)
{
    if (this->compositeName)
    {
        free(this->compositeName);
    }
    free(this);
}

static void render(composite *this)
{
    if (!this->enabled)
    {
        return;
    }
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
    mvprintw(this->y, this->x + 1, " %s ", this->compositeName);
}

static composite *new (window *window, char *compositeName, int x, int y, int width, int height, int compositeRule)
{
    composite *composite_ptr = (composite *)malloc(sizeof(composite));
    char *compositeNameMem = (char *)calloc(strlen(compositeName) + 1, sizeof(char));
    memcpy(compositeNameMem, compositeName, strlen(compositeName));
    *composite_ptr = (composite){
        .window = window,
        .compositeName = compositeNameMem,
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .compositeRule = compositeRule,
        .enabled = true,
        .render = &render,
        .destroy = &destroy};
    return composite_ptr;
}

const struct CompositeClass composite_ = {.new = &new};
