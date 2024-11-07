#include "char_render.h"

int testScreenCentering(void) {
  int row = 0, col = 0;
  int r_old = 0, c_old = 0;
  keys key;

  sprite *test = sprite_.new("test/animtest_2_mask.spr");
  sprite *test2 = sprite_.new("debug/center.spr");

  if (loadSprite(test) || loadSprite(test2)) {
    test->freeBuffer(test);
    endwin();

    return RENDER_ERROR_FS;
  }
  int frame = 0;

  int x = 0, y = 0;
  int x_o = x, y_o = y;
  int w = test->graphics[0]->width, h = test->graphics[0]->height;
  int hspeed = 1, vspeed = 1;

  getchar();
  setlocale(LC_CTYPE, "C-UTF-8"); /* inititalizing locale */
  initscr();                      /* start the curses mode */
  initKeyboard();                 /* start keyboard nodelay for stdscr */
  while (true) {
    usleep(1000000 / FPS);          // halt execution for 17ms => 60fps
    graphic *g = test->graphics[0]; // advance frame
    graphic *g2 = test2->graphics[frame % test2->frameCount]; // advance frame

    if (keyHandle(&key) != RENDER_CONTINUE) {
      break;
    }

    mvprintw(row - 1, 0, "baud rate %d row %d col %d\n", baudrate(), row, col);
    if (!adjustScreen(&row, &col, &r_old, &c_old)) {
      drawPrimitiveRect(g2->data, g2->height, (col >> 1) - 14,
                        (row >> 1) - 1); // fast 2 division bc yes
      drawMaskedRect(g->data, g->mask, g->width, g->height, x, y);

      x += hspeed;
      y += vspeed;
      if (x >= (col - w - 1) || x < 0) {
        hspeed = -hspeed;
      }
      if (y > (row - h - 1) || y < 0) {
        vspeed = -vspeed;
      }
    }

    refresh();

    clearMaskedRect(g->mask, g->width, g->height, x, y);
    frame++;
  }
  test->freeBuffer(test);
  test2->freeBuffer(test2);
  endwin();
  printf("got here\n");
  return RENDER_OK;
}

int keyHandle(keys *key) {
  switch (KeyPressed()) {
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

int adjustScreen(int *row, int *col, int *r_old, int *c_old) {
  getmaxyx(stdscr, *row, *col); /* get the number of rows and columns */
  if (*r_old != *row || *c_old != *col) {
    clear();
    *r_old = *row;
    *c_old = *col;
  }
  if (*row < MIN_ROW || *col < MIN_COL) {
    char *mesg = "Screen too small";
    mvprintw(*row >> 1, (*col - strlen(mesg)) >> 1, "%s", mesg);
    return SCREEN_TOO_SMALL;
  }
  return SCREEN_OK;
}

void drawPrimitiveRect(char **data, int lines, int x, int y) {
  for (int i = 0; i < lines; i++) {
    mvprintw(y + i, x, "%s", data[i]);
  }
}

void drawMaskedRect(char **data, char **mask, int width, int height, int x,
                    int y) {
  for (int py = 0; py <= height; py++) {
    for (int px = 0; px <= width; px++) {
      if (mask[py][px] == 'x') {
        move(y + py, x + px);
        addch(data[py][px]);
      }
    }
  }
}

void clearMaskedRect(char **mask, int width, int height, int x, int y) {
  for (int py = 0; py <= height; py++) {
    for (int px = 0; px <= width; px++) {
      if (mask[py][px] != 'x') {
        move(y + py, x + px);
        addch(' ');
      }
    }
  }
}
