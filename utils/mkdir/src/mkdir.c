#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
  int p = 0;
  int mode = 0700; /* mode_t is just a typedef of __mode_t, and __mode_t is just a typedef of an int32. */
  struct stat st;
  if (argc == 1)
    return -1;
  if (argc == 2) { 
    if (stat(argv[1], &st) == -1) {
      mkdir(argv[1], mode);
    }
  } else {
    int i;
    for (i = 1; i < argc; i++) {
      if (strchr(argv[i], 'm') != NULL && argv[i][0] == '-') {
        mode = atoi(argv[i+1]);
      }
      if (strchr(argv[i], 'p') != NULL && argv[i][0] == '-') {
        p = 1;
      }
    }
  }
  if (p) {
    int dircc = 0;
    char* directories;
    directories = strtok(argv[argc-1], "/");

    while (directories != NULL) {
      if (stat(directories, &st) == -1) {
        mkdir(directories, mode);
      }
      dircc++;
      chdir(directories);
      
      directories = strtok(NULL, "/");
    }
    int j;
    for (j = 0; j < dircc; j++) {
      chdir("..");
    }
  }
  return 0;
}
