#include "shell.h"
/**
 * _getline_command - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *_getline_command(void)
{
	char *input = NULL;
	size_t inputsize = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&input, &inputsize, stdin) == -1)
	{
		free(input);
		return (NULL);
	}

	return (input);
}
