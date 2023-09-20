#include "shell.h"
/**
 * path_separate - function that separates the path in new strings
 * @arg: command input
 * @env: environment
 * Return: pointer to strings
 */
int path_separate(char **arg, char **env)
{
	char *token = NULL, *pat_rel = NULL, *path_abs = NULL;
	size_t path_value, command;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	pat_rel = pathcheck(env);
	if (!pat_rel)
		return (-1);
	token = _strtok(pat_rel, ":");
	command = _strlen(*arg);

	for (; token; token = _strtok(NULL, ":"))
	{
		path_value = _strlen(token);
		path_abs = malloc(sizeof(char) * (path_value + command + 2));
		if (!path_abs)
		{
			free(pat_rel);
			return (-1);
		}
		path_abs = _strcpy(path_abs, token);
		_strcat(path_abs, "/");
		_strcat(path_abs, *arg);

		if (stat(path_abs, &stat_lineptr) == 0)
		{
			*arg = path_abs;
			free(pat_rel);
			return (0);
		}
		free(path_abs);
	}
	free(pat_rel);
	return (-1);
}
