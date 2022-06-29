/* c-console-render.c
 *
 * Copyright 2022 bucccket
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name(s) of the above copyright
 * holders shall not be used in advertising or otherwise to promote the sale,
 * use or other dealings in this Software without prior written
 * authorization.
 */

#include <stdio.h>
#include <stdlib.h>

#include "render_pipeline/char_render.h"

void parseArgs(int argc, char *argv[]);

int main(int argc, char *argv[])
{

  parseArgs(argc, argv);
  testScreenCentering();
  printf("end.\n");

  return EXIT_SUCCESS;
}

void parseArgs(int argc, char *argv[])
{
  printf("cmdline args count=%d\n", argc);

  /* First argument is executable name only */
  printf("exe name=%s\n", argv[0]);

  for (int i = 1; i < argc; i++)
  {
    printf("arg%d=%s\n", i, argv[i]);
  }
}
