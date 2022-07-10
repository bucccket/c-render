#include "composite.h"

static void destroy(composite *this)
{
    // window is backreferenced in composite, so we don't need to free it here
    free(this);
}

static composite *new (window *window, char *compositeName, int x, int y, int width, int height, int compositeRule)
{
    composite *composite_ptr = (composite *)malloc(sizeof(composite));
    *composite_ptr = (composite){.window = window, .compositeName = compositeName, .x = x, .y = y, .width = width, .height = height, .compositeRule = compositeRule, .destroy = &destroy};
    return composite_ptr;
}

const struct CompositeClass composite_ = {.new = &new};