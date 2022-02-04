#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <errno.h>
#include <unistd.h>

int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0) {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

int main(int argc, char* argv[]) {
  if (argc == 1)
    while (1) printf("y\n");
  else {
    if (argv[1][0] == '-' && argv[1][1] == 'r') {
      int rate = (int)((float)(1 * 1000) / (float)(atoi(&argv[1][2]) * 1000) * (float)1000);
      if (argc > 2) {
        while (1) {
          printf("%s\n", argv[2]);
          msleep(rate);
        }
      } else {
        while(1) {
          printf("y\n");
          msleep(rate);
        }
      }
    } else {
      while (1) printf("%s\n", argv[1]);
    }
  }
  return 0;
}
