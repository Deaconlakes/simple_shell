#include "newheader.h"
/**
 * manageEnviron - function manage the environment variables
 * @args: array of strings that rep the comm line args
 * @option: int that specifies whic op to perfom
 */
char **environ;
int manageEnviron(char *args[], int option)
{
    char **env_aux = environ;

    while (*env_aux != 0) {
        switch (option) {
            case 0:
                printf("%s\n", *env_aux);
                env_aux++;
                break;
            case 1:
                if (args[1] == NULL || args[2] == NULL) {
                    printf("Error: Not enough input arguments\n");
                    return (-1);
                }
                if (getenv(args[1]) != NULL) {
                    printf("Warning: The variable has been overwritten\n");
                } else {
                    printf("Info: The variable has been created\n");
                }
                if (args[2] == NULL) {
                    setenv(args[1], "", 1);
                } else {
                    setenv(args[1], args[2], 1);
                }
                return (0);
                break;
            case 2:
                if (args[1] == NULL) {
                    printf("Error: Not enough input arguments\n");
                    return (-1);
                }
                if (getenv(args[1]) != NULL) {
                    unsetenv(args[1]);
                    printf("Info: The variable has been erased\n");
                } else {
                    printf("Warning: The variable does not exist\n");
                }
                return (0);
                break;
        }
        env_aux++;
    }

    return (0);
}
