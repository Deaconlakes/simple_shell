#include "newheader.h"

/**
* Method used to handle the commands entered via the standard input
*/ 
int handle(char * array_t[100]) {
    int i = 0;
    int j = 0;
    char cdir[1024];
    int fileDescriptor;
    int standardOut;
    
    int aux;
    int background = 0;
    
    char *args_aux[256];
    
    for (j = 0; array_t[j] != NULL; j++) {
        if ((strcmp(array_t[j], ">") == 0) || (strcmp(array_t[j], "<") == 0) || (strcmp(array_t[j], "&") == 0)) {
            break;
        }
        args_aux[j] = array_t[j];
    }
    
    if (strcmp(array_t[0], "exit") == 0) exit(0);
    else if (strcmp(array_t[0], "pwd") == 0) {
        if (array_t[j] != NULL) {
            if ((strcmp(array_t[j], ">") == 0) && (array_t[j+1] != NULL)) {
                fileDescriptor = open(array_t[j+1], O_CREAT | O_TRUNC | O_WRONLY, 0600); 
                standardOut = dup(STDOUT_FILENO); 
                dup2(fileDescriptor, STDOUT_FILENO); 
                close(fileDescriptor);
                printf("%s\n", getcwd(cdir, 1024));
                dup2(standardOut, STDOUT_FILENO);
            }
        } else {
            printf("%s\n", getcwd(cdir, 1024));
        }
    } 
    else if (strcmp(array_t[0], "clear") == 0) system("clear");
    else if (strcmp(array_t[0], "cd") == 0) changedir(array_t);
    else if (strcmp(array_t[0], "environ") == 0) {
        if (array_t[j] != NULL) {
            if ((strcmp(array_t[j], ">") == 0) && (array_t[j+1] != NULL)) {
                fileDescriptor = open(array_t[j+1], O_CREAT | O_TRUNC | O_WRONLY, 0600); 
                standardOut = dup(STDOUT_FILENO); 
                dup2(fileDescriptor, STDOUT_FILENO); 
                close(fileDescriptor);
                manageEnviron(array_t, 0);
                dup2(standardOut, STDOUT_FILENO);
            }
        } else {
            manageEnviron(array_t, 0);
        }
    }
    else if (strcmp(array_t[0], "setenv") == 0) manageEnviron(array_t, 1);
    else if (strcmp(array_t[0], "unsetenv") == 0) manageEnviron(array_t, 2);
    else {
        for (i = 0; array_t[i] != NULL && background == 0; i++) {
            if (strcmp(array_t[i], "&") == 0) {
                background = 1;
            } else if (strcmp(array_t[i], "|") == 0) {
                pipeHandler(array_t);
                return 1;
            } else if (strcmp(array_t[i], "<") == 0) {
                aux = i + 1;
                if (array_t[aux] == NULL || array_t[aux+1] == NULL || array_t[aux+2] == NULL) {
                    printf("Not enough input arguments\n");
                    return -1;
                } else {
                    if (strcmp(array_t[aux+1], ">") != 0) {
                        printf("Usage: Expected '>' and found %s\n", array_t[aux+1]);
                        return -2;
                    }
                }
                fileIO(args_aux, array_t[i+1], array_t[i+3], 1);
                return 1;
            }
            else if (strcmp(array_t[i], ">") == 0) {
                if (array_t[i+1] == NULL) {
                    printf("Not enough input arguments\n");
                    return -1;
                }
                fileIO(args_aux, NULL, array_t[i+1], 0);
                return 1;
            }
        }
        args_aux[i] = NULL;
        prog(args_aux, background);
    }
    return 1;
}
