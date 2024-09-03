#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 80
#define MAX_LINE 80

void separar_comandos(char *input, char *args[]) {
    int i = 0;
    char *token = strtok(input, " \n");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;  
}

int main() {
    char *args[MAX_ARGS];
    char input[MAX_LINE];
    pid_t pid;
    int status;
    char caminho[MAX_LINE];

    while (1) {
        printf("minhashell> ");
        fgets(input, MAX_LINE, stdin);
        separar_comandos(input, args);

         if (args[0] == NULL) {
            continue; 
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid = fork();
        
        /*processo filho*/
        if (pid == 0) {
            if (strcmp(args[0], "meucat") == 0 || strcmp(args[0], "meuecho") == 0) {
                strcpy(caminho, "./");
                strcat(caminho, args[0]);
                execvp(caminho, args);
            } 
            else {
                strcpy(caminho, "/bin/");
                strcat(caminho, args[0]);
                execvp(caminho, args);
                execvp(args[0], args);
            }
            exit(1);
        } 
        /*Processo filho*/
        else {
            waitpid( -1, &status, 0);
        }
    }

    return 0;
}
