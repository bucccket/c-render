#include "keyboard.h"

int KeyPressed(int* pKeyCode)
{
 int KeyIsPressed = 0;
 struct timeval tv;
 fd_set rdfs;

 tv.tv_sec = tv.tv_usec = 0;

 FD_ZERO(&rdfs);
 FD_SET(STDIN_FILENO, &rdfs);

 select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);

 if(FD_ISSET(STDIN_FILENO, &rdfs))
 {
  int KeyCode = getchar();
  if(pKeyCode != NULL) *pKeyCode = KeyCode;
  KeyIsPressed = 1;
 }

 return KeyIsPressed;
}
