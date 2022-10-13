#include "statuslabel.h"

static void destroy(statuslabel *this)
{
    if(this->content){
      free(this->content);
    }
    free(this);
}

static void render(statuslabel *this)
{
    mvprintw(this->window->height-2, 2, "%s", this->content);
}

static statuslabel *new (struct window_ *window, char *content)
{
    window->resize(window,window->width,window->height-2);
    window->render(window);

    statuslabel *statuslabel_ptr = (statuslabel *)malloc(sizeof(statuslabel));
    char* allocContent = (char*)calloc(strlen(content)+1,sizeof(char));
    memcpy (allocContent,content, strlen(content));
    *statuslabel_ptr = (statuslabel){
        .window = window, 
        .content = allocContent, 
        .render = &render, 
        .destroy = &destroy};
    return statuslabel_ptr;
}

const struct StatuslabelClass statuslabel_ = {.new = &new};
