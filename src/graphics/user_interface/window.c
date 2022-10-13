#include "window.h"

// TODO: add realloc check for memory overflow
static void add(window *this, element *element)
{
    this->elements = realloc(this->elements, sizeof(struct userInterfaceElement *) * (this->elementsCount + 1));
    this->elements[this->elementsCount++] = element; // add element to array
}

static void destroy(struct window_ *this)
{
    for (int i = 0; i < this->elementsCount; i++)
    {
        element *elem = this->elements[i];
        if (elem)
        {
            switch (elem->type)
            {
            case COMPOSITE:
                elem->composite->destroy(elem->composite);
                break;
            case MENUBAR:
                elem->menubar->destroy(elem->menubar);
                break;
            case STATUSLABEL:
                elem->statuslabel->destroy(elem->statuslabel);
                break;
            }
            //free(elem); //TODO: MALLOC all elements
        }
        else
        {
            fprintf(stderr, "[ERROR] %s->composites[%d] is NULL\n", this->title, i);
        }
    }
    free(this->elements); // iteratively free all composites
    free(this);
}

static void render(struct window_ *this)
{
    int x, y = 0;
    for (x = 0; x < this->width; x++)
    {
        for (y = 0; y < this->height; y++)
        {
            if (y <= 0 || y >= (this->height - 1))
            {
                mvaddch(y, x, W_HLINE);
            }
            if (x <= 0 || x >= (this->width - 1))
            {
                mvaddch(y, x, W_VLINE);
                if (y == 0)
                {
                    mvaddch(y, x, x == 0 ? W_ULCORNER : W_URCORNER);
                }
                else if (y >= (this->height - 1))
                {
                    mvaddch(y, x, x == 0 ? W_LLCORNER : W_LRCORNER);
                }
            }
        }
    }

    for (int i = 0; i < this->elementsCount; i++)
    {
        element *elem = this->elements[i];
        switch (elem->type)
        {
        case COMPOSITE:
            elem->composite->render(elem->composite);
            break;
        case MENUBAR:
            elem->menubar->render(elem->menubar);
            break;
        case STATUSLABEL:
            elem->statuslabel->render(elem->statuslabel);
            break;
        }
    }
}

void resize(struct window_ *this, int width, int height)
{
    this->width = width;
    this->height = height;
}

static window *new (int width, int height, int xCell, int yCell, char *title)
{
    window *window_ptr = (window *)malloc(sizeof(window));
    element **element_ptr = (element **)calloc(1, sizeof(element *));
    *window_ptr = (window){
        .width = width,
        .height = height,
        .xCell = xCell,
        .yCell = yCell,
        .title = title,
        .elements = element_ptr,
        .elementsCount = 0,
        .add = &add,
        .destroy = &destroy,
        .render = &render,
        .resize = &resize};
    return window_ptr;
}

const struct WindowClass window_ = {.new = &new};