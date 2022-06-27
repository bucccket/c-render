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

  graphic *g = test.graphics[0];
  char *arr[] = {"       ","       "," +---+ ", " |>o<| ", " | ^ | ", " |1 3| ", " +---+ ", "       ","       ", NULL};

  int x = 0, y = 5;
  int x_o = 0, y_o = 5;
  int w = test.graphics[0]->width+2, h = test.graphics[0]->height+4;
  int hspeed = 1, vspeed = 1;

  getchar();

  initscr();      /* start the curses mode */
  initKeyboard(); /* start keyboard nodelay for stdscr */
  while (true)
  {
    usleep(1000000 / 6); // halt execution for 17ms => 60fps

    int keyStatus = keyHandle(&key);
    if (keyStatus != RENDER_CONTINUE)
    {
      return keyStatus;
    }

    if (!adjustScreen(&row, &col, &r_old, &c_old))
    {
      drawPrimitiveRect(stdscr, arr, x, y);
      mvprintw(row / 2, (col - strlen(mesg)) / 2, "%s", mesg);
      mvprintw(row - 1, 0, "baud rate %d row %d col %d\n", baudrate(), row, col);
      mvprintw(row - 1, col - 1, "e");

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
    }

    refresh();
    curs_set(0); /* disable cursor */
  }
  endwin();
  return RENDER_OK;
}

int keyHandle(keys *key)
{
  switch (KeyPressed())
  {
  case 27:
    *key = K_ESC;
    endwin();
    return RENDER_OK;
    break;
  case 'w':
    *key = K_W;
    return RENDER_OK;
    break;
  default:
    *key = K_NONE;
    break;
  }
  return RENDER_CONTINUE;
}

int adjustScreen(int *row, int *col, int *r_old, int *c_old)
{
  getmaxyx(stdscr, *row, *col); /* get the number of rows and columns */
  if (*r_old != *row || *c_old != *col)
  {
    clear();
    *r_old = *row;
    *c_old = *col;
  }
  if (*row < MIN_ROW || *col < MIN_COL)
  {
    char *mesg = "Screen too small";
    mvprintw(*row / 2, (*col - strlen(mesg)) / 2, "%s", mesg);
    return SCREEN_TOO_SMALL;
  }
  return SCREEN_OK;
}

void drawPrimitiveRect(WINDOW *window, char **ptr, int x, int y)
{
  int offs = 0;
  while (*ptr != NULL)
  {
    mvprintw(y + offs++, x, *ptr++);
  }
}
