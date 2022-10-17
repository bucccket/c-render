#include "label.h"

static void destroy(label *this)
{
    if (this->content)
    {
        free(this->content);
    }
    free(this);
}

void setText(label *this, char *text){
    char *allocContent = (char *)calloc(strlen(content) + 1, sizeof(char));
    memcpy(allocContent, tihs->content, strlen(content));
}

static void render(label *this)
{
    mvprintw(this->y, this->x + 1, " %s ", this->content);
}

static label *new (window *window, char *content, int x, int y, int textstyle)
{
    label *label_ptr = (label *)malloc(sizeof(label));
    char *allocContent = (char *)calloc(strlen(content) + 1, sizeof(char));
    memcpy(allocContent, content, strlen(content));
    *label_ptr = (label){
        .window = window,
        .content = allocContent,
        .x = x,
        .y = y,
        .textstyle = textstyle,
        .render = &render,
        .destroy = &destroy};
    return label_ptr;
}

const struct LabelClass label_ = {.new = &new};
