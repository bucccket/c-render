#include "char_render.h"

int testScreenCentering(void){
  char *mesg="-> center <-";            /* message to be appeared on the screen */
  int row,col;                            /* to store the number of rows and *
                                           * the number of colums of the screen */
  int r_old = 0,c_old = 0;
  sprite test = sprite_.new("nonetest.spr");
  int spriteError = loadSprite(&test);
  if(!!spriteError){
    printf("Sprite error 0x%02X\n",spriteError);
    return RENDER_ERROR_FS;
  }
  char *arr[] = {"hello", "bye", NULL};
  time_t stop, start;
  double elapsed;
  int x = 0, y = 5;
  int w = 5, h = 2;
  int spd = 1;
  time(&start);
  getchar();

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
        return RENDER_OK;
      }else{
        mvprintw(row-3, 0, "got key %c #%d",key,key);
      }
    }

    drawPrimitiveRect(stdscr, arr, x, y);

    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
    mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
    printw("Try resizing your window and re-run");

    refresh();
    time(&stop);
    elapsed = difftime(stop,start);
    halfdelay (1);
    getch();
    x+=spd;
    if(x>(col-w)||x<0){
      spd =-spd;
    }
    elapsed = 0.0;
    clear();
  }
  endwin();
  return RENDER_OK;
}

void adjustScreen(int *row, int *col, int *r_old, int *c_old){
  getmaxyx(stdscr,*row,*col);               /* get the number of rows and columns */
    if(*r_old != *row || *c_old != *col){
      clear();
      *r_old = *row;
      *c_old = *col;
    }
}

void drawPrimitiveRect(WINDOW *window, char **ptr, int x, int y)
{
    int offs = 0;
    while (*ptr != NULL) {
        mvprintw(y+offs++,x,*ptr++);
    }
}
