#include "composite.h"

static void destroy(composite *this)
{
    free(this);
}

static void render(struct composite_ *this)
{
    int x, y = 0;

    if (this->x + this->width >= this->window->width || this->y + this->height >= this->window->height)
    {
        return;
    }

    for (x = 0; x < this->width; x++)
    {
        for (y = 0; y < this->height; y++)
        {
            if (y <= 0 || y >= (this->height - 1))
            {
                mvaddch(y + this->y, x + this->x, ACS_HLINE);
            }

            if (x <= 0 || x >= (this->width - 1))
            {
                mvaddch(y + this->y, x + this->x, ACS_VLINE);
                if (y == 0)
                {
                    mvaddch(y + this->y, x + this->x, x == 0 ? ACS_ULCORNER : ACS_URCORNER);
                }
                else if (y >= (this->height - 1))
                {
                    mvaddch(y + this->y, x + this->x, x == 0 ? ACS_LLCORNER : ACS_LRCORNER);
                }
            }
        }
    }
    mvprintw(this->y, this->x+1, " %s ", this->compositeName);
}

static composite *new (window *window, char *compositeName, int x, int y, int width, int height, int compositeRule)
{
    composite *composite_ptr = (composite *)malloc(sizeof(composite));
    *composite_ptr = (composite){.window = window, .compositeName = compositeName, .x = x, .y = y, .width = width, .height = height, .compositeRule = compositeRule, .render = &render, .destroy = &destroy};
    return composite_ptr;
}

const struct CompositeClass composite_ = {.new = &new};