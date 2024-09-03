#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int vetor[10] = {0};
  int i, status;
  int pid = fork();
  if (pid != 0) { /* do pai */
    for (i=0; i < 10; i++){
      vetor[i] += 1;
    
    }
    printf("Saída do Pai:\n");
    for (i = 0; i < 10; i++) {
        printf("%d %d\n", i, vetor[i]);
    }
    waitpid(-1, &status, 0);
    exit(0);
  }
  else { /* do filho */
    for (i=0; i < 10; i++){
      vetor[i] -= 1;
    }
    printf("Saída do filho:\n");
    for (i=0; i < 10; i++){
      printf("%d %d\n",i,vetor[i]);
    }
    exit(0);
  }
  
  return 0;
}
