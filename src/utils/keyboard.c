#include "keyboard.h"

void initKeyboard(void)
{
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
}

int KeyPressed()
{
  int c = wgetch(stdscr);

  if (c == ERR)
  {
    return 0;
  }
  return c;
}
