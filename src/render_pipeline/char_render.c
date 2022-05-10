#include "char_render.h"

void testScreenCentering(void){
  char mesg[]="-> center <-";            /* message to be appeared on the screen */
  int row,col;                            /* to store the number of rows and *
                                           * the number of colums of the screen */
  int r_old = 0,c_old = 0;
  initscr();                              /* start the curses mode */
  while(true){
    getmaxyx(stdscr,row,col);               /* get the number of rows and columns */
    if(r_old != row || c_old != col){
      clear();
      r_old = row;
      c_old = col;
    }

    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);         /* print the message at the
                                                              center of the screen */
    mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
    printw("Try resizing your window and re-run");

    refresh();
  }
  endwin();
}
