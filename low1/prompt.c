#include "shell.h"
/**
 * _getline_command - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *shellprompt(void)
{
	char *input = NULL;
	size_t inputsize = 0;
	char cwd [2040];
	
	if (isatty(STDIN_FILENO))
	{
		 if( getcwd(cwd, sizeof(cwd)))
		 {
		write(STDOUT_FILENO, "lekstesh", 8);
		write(STDOUT_FILENO, cwd, strlen(cwd));
		write(STDOUT_FILENO, "=>", 2);
	}
	}

	if (getline(&input, &inputsize, stdin) == -1)
	{
		free(input);
		return (NULL);
	}

	return (input);
}
