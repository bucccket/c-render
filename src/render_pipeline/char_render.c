#include "char_render.h"

/**
 * @brief used to test rendering on a screen in general
 *
 * @return int 0 on SUCCESS not 0 on FAILURE
 */
int testScreenCentering(void)
{
  int row, col;
  int r_old = 0, c_old = 0;
  keys key;

  sprite *test = sprite_.new("test/animtest_2_mask.spr");
  sprite *test2 = sprite_.new("debug/center.spr");

  if (test == NULL || test2 == NULL)
  {
    test->freeBuffer(test);
    endwin();

    return RENDER_ERROR_FS;
  }
  int frame = 0;

  int x = 0, y = 0;
  int w = test->graphics[0]->width, h = test->graphics[0]->height;
  int hspeed = 1, vspeed = 0;

  setlocale(LC_ALL, ""); /* inititalizing locale */
  initscr();             /* start the curses mode */
  initKeyboard();        /* start keyboard nodelay for stdscr */
  while (true)
  {
    usleep(1000000 / FPS);                                    // pass CPU time to system for n delay
    graphic *g = test->graphics[0];                           // advance animation frame (looped)
    graphic *g2 = test2->graphics[frame % test2->frameCount]; // advance animation frame (looped)

    if (keyHandle(&key) != RENDER_CONTINUE)
    {
      break;
    }

    mvprintw(row - 1, 0, "baud rate %d row %d col %d\n", baudrate(), row, col);
    if (!adjustScreen(&row, &col, &r_old, &c_old))
    {
      drawPrimitiveRect(g2->data, g2->height, (col >> 1) - 14, (row >> 1) - 1); // slightly faster math
      //drawMaskedRect(g->data, g->mask, g->width, g->height, x, y);

      x += hspeed;
      y += vspeed;
      if (x >= (col - w - 1) || x < 0)
      {
        hspeed = -hspeed;
      }
      if (y > (row - h - 1) || y < 0)
      {
        vspeed = -vspeed;
      }
      refresh();
      //clearMaskedRect(g->mask, g->width, g->height, x, y);
    }
    frame++;
  }
  test->freeBuffer(test);
  test2->freeBuffer(test2);
  endwin();
  printf("got here\n");
  return RENDER_OK;
}

/**
 * @brief handle keyboard input
 *
 * @param key keyboard enum
 * @return int return value determines if rendering should continue or not
 */
int keyHandle(keys *key)
{
  switch (KeyPressed())
  {
  case 27:
    *key = K_ESC;
    endwin();
    return RENDER_ABORT;
    break;
  case 'w':
    *key = K_W;
    return RENDER_ABORT;
    break;
  default:
    *key = K_NONE;
    break;
  }
  return RENDER_CONTINUE;
}

/**
 * @brief adaps row and col value and overrides screen if the resolution is too small
 *
 * @param row row pointer to window struct
 * @param col col pointer to window struct
 * @param r_old old row value to be compared to new row value
 * @param c_old old col value to be compared to new col value
 * @return int 0 on screen size ok and not 0 on too small screen
 */
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
    mvprintw(*row >> 1, (*col - strlen(mesg)) >> 1, "%s", mesg);
    return SCREEN_TOO_SMALL;
  }
  return SCREEN_OK;
}

/**
 * @brief draws unmaksed sprite on screen. Good for non-moving sprites
 *
 * @param data graphics data
 * @param lines height of sprite
 * @param x offset x
 * @param y offset y
 */
void drawPrimitiveRect(char **data, int lines, int x, int y)
{
  for (int i = 0; i < lines; i++)
  {
    mvprintw(y + i, x, data[i]);
  }
}

/**
 * @brief draw transparent/masked sprite on screen. Good for moving sprites
 *
 * @param data graphics data
 * @param mask alpha mask
 * @param width width dimension of sprite
 * @param height height dimension of sprite
 * @param x offset x
 * @param y offset y
 */
void drawMaskedRect(char **data, char **mask, int width, int height, int x, int y)
{
  for (int py = 0; py <= height; py++)
  {
    for (int px = 0; px <= width; px++)
    {
      if (mask[py][px] == 'x')
      {
        move(y + py, x + px);
        addch(data[py][px]);
      }
    }
  }
}

/**
 * @brief clear masked sprite on screen after drawing it
 *
 * @param mask alpha mask
 * @param width width dimension of sprite
 * @param height height dimension of sprite
 * @param x offset x
 * @param y offset y
 */
void clearMaskedRect(char **mask, int width, int height, int x, int y)
{
  for (int py = 0; py <= height; py++)
  {
    for (int px = 0; px <= width; px++)
    {
      if (mask[py][px] != 'x')
      {
        move(y + py, x + px);
        addch(' ');
      }
    }
  }
}
