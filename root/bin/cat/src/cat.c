/* Code written by Finxx1 on GitHub, released under the Unlicense. */

#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("Error: no arguments provided.");
    return -1;
  }
  struct stat* filesize = malloc(sizeof(struct stat));
  int fd, i;
  char* buf;
  for (i = 1; i < argc; i++) {
    fd = open(argv[i], O_RDONLY);
    if (fd < 0) printf("Error: can't open %s for reading!", argv[1]);
    fstat(fd, filesize);
    //printf("%lld", filesize->st_size);
    buf = calloc(filesize->st_size, 1);
    read(fd, buf, filesize->st_size);
    printf("%s", buf);
    free(buf);
    close(fd);
  }
  free(filesize);
  return 0;
}
