#include "shell.h"
/**
 * _getline_command - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *shellprompt(void)
{
	char *input = NULL;
	size_t inputsize = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "lekstesh=> ", 12);

	if (getline(&input, &inputsize, stdin) == -1)
	{
		free(input);
		return (NULL);
	}

	return (input);
}
