#include "shell.h"
/**
 * pathcheck - matches the tokenized input with a variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *pathcheck(char **env)
{
	size_t first = 0, var = 0, counter = 5;
	char *path = NULL;

	for (first = 0; strncmp(env[first], "PATH=", 5); first++)
		;
	if (env[first] == NULL)
		return (NULL);

	for (counter = 5; env[first][var]; var++, counter++)
		;
	path = malloc(sizeof(char) * (counter + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, counter = 0; env[first][var]; var++, counter++)
		path[counter] = env[first][var];

	path[counter] = '\0';
	return (path);
}
