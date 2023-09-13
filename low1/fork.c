#include "shell.h"
/**
 * _fork_fun - function that create a fork
 *@arg: command and values path
 *@av: Has the name of our program
 *@env: environment
 *@lineptr: command line for the user
 *@np: id of proces
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork(char **arg, char **av, char **env, char *input, int a, int c)
{
	pid_t child;
	int status;
	char *pattern = "%s: %d: %s: not located\n";

	child = fork();

	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, pattern, av[0], a, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(input);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
