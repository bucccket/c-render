#include "keyboard.h"

void initKeyboard(void)
{
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
}

void endKeyboard(void)
{
  nocbreak();
  echo();
  nodelay(stdscr, FALSE);
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
