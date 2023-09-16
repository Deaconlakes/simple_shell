#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);
char *_strchr(const char *s, int ch);
size_t _strspn(const char *s1, const char *s2);
size_t _strcspn(const char *s1, const char *s2);

int _values_path(char **arg, char **env);
char *pathcheck(char **env);
char *_getline_command(void);
void _getenv(char **env);
char **_get_token(char *lineptr);
char *_strtok(char *str, const char *delim);
char *shellprompt(void);
void _exits(char **arg, char *input, int _ext);
int dir(char* myargs[]);
int _fork(char **arg, char **av, char **env, char *input, int c);


#endif /* SHELL_H */
