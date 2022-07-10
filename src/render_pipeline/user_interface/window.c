#include "window.h"

static void addComposite(window *this, composite *cmp)
{
    this->composites = realloc(this->composites, sizeof(composite *) * (this->compositesCount + 1));
    this->composites[this->compositesCount++] = cmp; // size / offset difference
}

static void destroy(struct window_ *this)
{
    for (int i = 0; i < this->compositesCount; i++)
    {
        if (this->composites[i])
        {
            this->composites[i]->destroy(this->composites[i]);
        }
        else
        {
            fprintf(stderr, "[ERROR] %s->composites[%d] is NULL\n", this->title, i);
        }
    }
    free(this->composites); // iteratively free all composites
    free(this);
}

static void render(struct window_ *this)
{
    int x, y = 0;

    for (x = 0; x < this->width; x++)
    {
        for (y = 0; y < this->height; y++)
        {
            if (y == 0 || y == (this->height - 1))
            {
                mvaddch(y, x, '-');
            }
            if (x <= 0 || x >= (this->width - 1))
            {
                mvaddch(y, x, '|');
            }
        }
    }
}

static window *new (int width, int height, char *title)
{
    window *window_ptr = (window *)malloc(sizeof(window));
    composite **composite_ptr = (composite **)calloc(1, sizeof(composite *));
    *window_ptr = (window){.width = width, .height = height, .title = title, .composites = composite_ptr, .compositesCount = 0, .addComposite = &addComposite, .destroy = &destroy, .render = &render};
    return window_ptr;
}

const struct WindowClass window_ = {.new = &new};