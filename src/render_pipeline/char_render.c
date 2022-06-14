#include "char_render.h"

void testScreenCentering(void){
  char *mesg="-> center <-";            /* message to be appeared on the screen */
  int row,col;                            /* to store the number of rows and *
                                           * the number of colums of the screen */
  int r_old = 0,c_old = 0;
  initscr();                              /* start the curses mode */
  initKeyboard();                         /* start keyboard nodelay for stdscr */
  while(true){
    curs_set(0);                            /* disable cursor */
    adjustScreen(&row,&col,&r_old,&c_old);

    int key = KeyPressed();
    if(key!=0){
      if(key == 27){
        mvprintw(row-3, 0, "exiting",key,key);
        endwin();
        return;
      }else{
        mvprintw(row-3, 0, "got key %c #%d",key,key);
      }
    }

    char *arr[] = {"hello", "bye", NULL};
    drawPrimitiveRect(stdscr, arr);

    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
    mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
    printw("Try resizing your window and re-run");

    refresh();
  }
  endwin();
}

void adjustScreen(int *row, int *col, int *r_old, int *c_old){
  getmaxyx(stdscr,*row,*col);               /* get the number of rows and columns */
    if(*r_old != *row || *c_old != *col){
      clear();
      *r_old = *row;
      *c_old = *col;
    }
}

void drawPrimitiveRect(WINDOW *window, char **ptr)
{
    int offs = 0;
    while (*ptr != NULL) {
        mvprintw(5+offs++,5,*ptr++);
    }
}
