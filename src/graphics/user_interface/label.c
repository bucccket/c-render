#include "label.h"

static void destroy(label *this)
{
    if (this->content)
    {
        free(this->content);
    }
    free(this);
}

static void setText(label *this, char *text)
{
    char *allocContent = (char *)calloc(strlen(text) + 1, sizeof(char));
    memcpy(allocContent, text, strlen(text));
    this->content = allocContent;
}

static void render(label *this)
{
    if (!this->enabled)
    {
        return;
    }
    mvprintw(this->x, this->y, "%s", this->content);
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
        .enabled = true,
        .render = &render,
        .setText = &setText,
        .destroy = &destroy};
    return label_ptr;
}

const struct LabelClass label_ = {.new = &new};
