/* Code written by Finxx1 on GitHub, released under the Unlicense. */

/* Fun facts:
  This code conforms to C89.
  The code for GNU echo is 277 lines, while this program is only 22 lines. That means that this version of echo is 12.5x
    smaller than GNU echo.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  int n = 0;
  if (!strcmp(argv[1], "-n"))
    n++;
  int i;
  for (i = 1 + n; i < argc; i++) {
    printf("%s", argv[i]);
  }
  if (!n)
    printf("\n");
  return 0;
}
