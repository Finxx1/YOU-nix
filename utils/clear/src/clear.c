/* Code written by Finxx1 on GitHub, released under the Unlicense. */

/* Fun facts:
  Code conforms to C89.
  Code should work on both windows and unix.
  Requires ANSI escape codes to work on terminal if on unix.
  Will work on every version of windows after NT 4.
  Clear is usually a builtin command, not a standalone executable.
*/

#include <stdio.h>

#ifdef _WIN32
  #include <windows.h>
  #include <conio.h>
#else
  #include <sys/ioctl.h>
  #include <unistd.h>
#endif

int main() {
#ifdef _WIN32
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  int rows = csbi.srWindow.Bottom - csbi.srWindow.Top;
#else
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int rows = w.ws_row;
#endif
  int i;
  for (i = 0; i < rows - 1; i++) {
    printf("\n");
  }
#ifdef _WIN32
  COORD Coord;
  Coord.X = 0;
  Coord.Y = 0;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
#else  
  printf("\033[%d;%dH", 1, 1);
#endif
  return 0;
}
