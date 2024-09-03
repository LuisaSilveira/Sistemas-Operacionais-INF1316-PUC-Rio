#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  for (i = 1; i < argc-1; i++)
  {
    (void) printf("%s%s", argv[i], " ");
  }
  (void) printf("%s%s", argv[argc-1], "\n");
  return EXIT_SUCCESS;
}

