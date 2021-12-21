#include <stdio.h>
#include <string.h>

/* #include <sys/param.h> */
#include <sys/utsname.h>

int main(int argc, char* argv[]) {
  struct utsname os;
  uname(&os);
  
  if (argc == 1) {
    printf("%s\n", os.sysname);
  } else {
    int i;
    for (i = 0; i < argc; i++) {
      if (strchr(argv[i], 'a') != NULL && argv[i][0] == '-') {
        printf("%s %s %s %s %s ", os.sysname, os.nodename, os.release, os.version, os.machine);
      }
      if (strchr(argv[i], 'm') != NULL && argv[i][0] == '-') {
        printf("%s ", os.machine);
      }
      if (strchr(argv[i], 'n') != NULL && argv[i][0] == '-') {
        printf("%s ", os.nodename);
      }
      /*
      if (strchr(argv[i], 'p') != NULL && argv[i][0] == '-') {
        printf("%s ", MACHINE_ARCH);
      }
      For some reason, this code will not compile on macOS even though it should be defined in sys/param. */
      if (strchr(argv[i], 'r') != NULL && argv[i][0] == '-') {
        printf("%s ", os.release);
      }
      if (strchr(argv[i], 's') != NULL && argv[i][0] == '-') {
        printf("%s ", os.sysname);
      }
      if (strchr(argv[i], 'v') != NULL && argv[i][0] == '-') {
        printf("%s ", os.version);
      }
    }
  }
  
  printf("\n");
  
  return 0;
}
