#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

typedef int status;

#define COMMAND 1
#define VALS 2

void error(char* str) {
  printf("%s\n", str);
}

int main() {
  status currentstatus = COMMAND;
  char command = ' ';
  char parse[MAX_LEN];
  while (1) {
    if (currentstatus == COMMAND)
      printf("\u03BB ");
    else
      printf("\u0394 ");
    fgets(parse, MAX_LEN, stdin);
    
    if (!strcmp(parse, "exit\n"))
      break;
    if (currentstatus == VALS) {
      float total = 0;
      char* valparse;
      valparse = strtok(parse, " ");
      total = atof(valparse);
      valparse = strtok(NULL, " ");
      
      while (valparse != NULL) {
        if (command == 'A')
          total += atof(valparse);
        if (command == 'S')
          total -= atof(valparse);
        if (command == 'D')
          total /= atof(valparse);
        if (command == 'M')
          total *= atof(valparse);
        if (command == 'E')
          total = pow(total, atof(valparse));
        valparse = strtok(NULL, " ");
      }
      printf("%f\n", total);
      currentstatus = COMMAND;
      continue;
    }
    if (currentstatus == COMMAND) {
      if (!strcmp(parse, "+\n"))
        command = 'A';
      else if (!strcmp(parse, "-\n"))
        command = 'S';
      else if (!strcmp(parse, "/\n"))
        command = 'D';
      else if (!strcmp(parse, "*\n"))
        command = 'M';
      else if (!strcmp(parse, "^\n"))
        command = 'E';
      else {
        error("Invalid operation");
        continue;
      }
      currentstatus = VALS;
    }
  }
  return 0;
}
