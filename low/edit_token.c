#include "shell.h"

/**
 * _get_token - get token of string
 * @lineptr: command user
 * Return: To a pointer
 */
char **_get_token(char *lineptr)
{
    char **user_command = NULL;
    char *token = NULL;
    size_t i = 0;
    int size = 0;

    if (lineptr == NULL)
        return (NULL);

    while (lineptr[i])
    {
        if (lineptr[i] == ' ')
            size++;
        i++;
    }
    if ((size + 1) == _strlen(lineptr))
        return (NULL);
    user_command = malloc(sizeof(char *) * (size + 2));
    if (user_command == NULL)
        return (NULL);

    token = _strtok(lineptr, " \n\t\r");
    i = 0;
    while (token != NULL)
    {
        user_command[i] = token;
        token = _strtok(NULL, " \n\t\r");
        i++;
    }
    user_command[i] = NULL;
    return (user_command);
}

