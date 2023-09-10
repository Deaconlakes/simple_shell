#include "header.h"

/**
* Method used to handle the commands entered via the standard input
*/ 
int commandHandler(char * args[]) {
    int i = 0;
    int j = 0;
    
    int fileDescriptor;
    int standardOut;
    
    int aux;
    int background = 0;
    
    char *args_aux[256];
    
    for (j = 0; args[j] != NULL; j++) {
        if ((strcmp(args[j], ">") == 0) || (strcmp(args[j], "<") == 0) || (strcmp(args[j], "&") == 0)) {
            break;
        }
        args_aux[j] = args[j];
    }
    
    if (strcmp(args[0], "exit") == 0) exit(0);
    else if (strcmp(args[0], "pwd") == 0) {
        if (args[j] != NULL) {
            if ((strcmp(args[j], ">") == 0) && (args[j+1] != NULL)) {
                fileDescriptor = open(args[j+1], O_CREAT | O_TRUNC | O_WRONLY, 0600); 
                standardOut = dup(STDOUT_FILENO); 
                dup2(fileDescriptor, STDOUT_FILENO); 
                close(fileDescriptor);
                printf("%s\n", getcwd(currentDirectory, 1024));
                dup2(standardOut, STDOUT_FILENO);
            }
        } else {
            printf("%s\n", getcwd(currentDirectory, 1024));
        }
    } 
    else if (strcmp(args[0], "clear") == 0) system("clear");
    else if (strcmp(args[0], "cd") == 0) changeDirectory(args);
    else if (strcmp(args[0], "environ") == 0) {
        if (args[j] != NULL) {
            if ((strcmp(args[j], ">") == 0) && (args[j+1] != NULL)) {
                fileDescriptor = open(args[j+1], O_CREAT | O_TRUNC | O_WRONLY, 0600); 
                standardOut = dup(STDOUT_FILENO); 
                dup2(fileDescriptor, STDOUT_FILENO); 
                close(fileDescriptor);
                manageEnviron(args, 0);
                dup2(standardOut, STDOUT_FILENO);
            }
        } else {
            manageEnviron(args, 0);
        }
    }
    else if (strcmp(args[0], "setenv") == 0) manageEnviron(args, 1);
    else if (strcmp(args[0], "unsetenv") == 0) manageEnviron(args, 2);
    else {
        for (i = 0; args[i] != NULL && background == 0; i++) {
            if (strcmp(args[i], "&") == 0) {
                background = 1;
            } else if (strcmp(args[i], "|") == 0) {
                pipeHandler(args);
                return 1;
            } else if (strcmp(args[i], "<") == 0) {
                aux = i + 1;
                if (args[aux] == NULL || args[aux+1] == NULL || args[aux+2] == NULL) {
                    printf("Not enough input arguments\n");
                    return -1;
                } else {
                    if (strcmp(args[aux+1], ">") != 0) {
                        printf("Usage: Expected '>' and found %s\n", args[aux+1]);
                        return -2;
                    }
                }
                fileIO(args_aux, args[i+1], args[i+3], 1);
                return 1;
            }
            else if (strcmp(args[i], ">") == 0) {
                if (args[i+1] == NULL) {
                    printf("Not enough input arguments\n");
                    return -1;
                }
                fileIO(args_aux, NULL, args[i+1], 0);
                return 1;
            }
        }
        args_aux[i] = NULL;
        launchProg(args_aux, background);
    }
    return 1;
}
