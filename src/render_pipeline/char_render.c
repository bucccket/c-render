#include "char_render.h"

int testScreenCentering(void)
{
  int row, col;
  int r_old = 0, c_old = 0;
  clock_t begin = clock(), end;
  double time_ms;
  keys key;

  char *mesg = "-> center <-";

  sprite test = sprite_.new("nonetest.spr");
  int spriteError = loadSprite(&test);
  if (!!spriteError)
  {
    printf("Sprite error 0x%02X\n", spriteError);
    return RENDER_ERROR_FS;
  }

  char *arr[] = {"hello", " bye ", NULL};
  int x = 0, y = 5;
  int x_o = 0, y_o = 5;
  int w = 5, h = 2;
  int hspeed = 1, vspeed = 1;

  getchar();

  initscr();      /* start the curses mode */
  initKeyboard(); /* start keyboard nodelay for stdscr */
  while (true)
  {
    switch (KeyPressed())
    {
    case 27:
      key = K_ESC;
      endwin();
      return RENDER_OK;
      break;
    case 'w':
      key = K_W;
      break;
    default:
      key = K_NONE;
      break;
    }

    drawPrimitiveRect(stdscr, arr, x, y);

    mvprintw(row / 2, (col - strlen(mesg)) / 2, "%s", mesg);
    mvprintw(row - 2, 0, "baud rate %d\ttime on frame %lf\n", baudrate(), time_ms);
    printw("Try resizing your window and re-run");

    end = clock();
    time_ms = (double)(end - begin) / CLOCKS_PER_SEC;

    if (time_ms >= 0.017)
    {
      adjustScreen(&row, &col, &r_old, &c_old);

      x_o = x;
      y_o = y;
      x += hspeed;
      y += vspeed;
      if (x >= (col - w - 1) || x < 0)
      {
        hspeed = -hspeed;
      }
      if (y > (row - h) || y < 0)
      {
        vspeed = -vspeed;
      }
      time_ms = 0.0;
      begin = clock();
      refresh();
      curs_set(0); /* disable cursor */
    }
  }
  endwin();
  return RENDER_OK;
}

void adjustScreen(int *row, int *col, int *r_old, int *c_old)
{
  getmaxyx(stdscr, *row, *col); /* get the number of rows and columns */
  if (*r_old != *row || *c_old != *col)
  {
    clear();
    *r_old = *row;
    *c_old = *col;
  }
}

void drawPrimitiveRect(WINDOW *window, char **ptr, int x, int y)
{
  int offs = 0;
  while (*ptr != NULL)
  {
    mvprintw(y + offs++, x, *ptr++);
  }
}
