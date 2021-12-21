/* Code written by Finxx1 on GitHub, released under the Unlicense. */

/* Fun facts:
  Code conforms to C89.
  Code should work on both windows and unix.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif

int main(int argc, char* argv[]) {
  if (argc > 1) {
    if (!strcmp(argv[1], "-P")) {
      char dir[256];
#ifdef _WIN32
      if (_getcwd(dir, sizeof(dir)) != NULL)
#else
      if (getcwd(dir, sizeof(dir)) != NULL)
#endif
        printf("%s\n", dir);
      else
        printf("An unknown error has occured.\n");
      return 0;
    }
  }

  printf("%s\n", getenv("PWD"));
  return 0;
}
