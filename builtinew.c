#include "shell.h"
/**
 * _exits- this function closes the simple_shell when
 * @arg: pointer with the direction argument.
 * @input: standar input string
 * @_ext: value of exit
 * Return: None
 */
void _exits(char **arg, char *input, int _ext)
{
	int exit_switch = 0;

	if (!arg[1])
	{
		free(input);
		free(arg);
		write(1, "Goodbye Friend!\n", 16);
		exit(_ext);
	}
	exit_switch = atoi(arg[1]);

	free(input);
	free(arg);
	exit(exit_switch);
}

/**
 *_getenv - function to get all env
 *@env: enviroment
 *@var: input variable
 *Return: 0
 */

void _getenv(char **env, char *var)
{
	size_t stat = 0;

	while (env[stat])
	{
		if (!var || strncmp(env[stat], var, strlen(var)) == 0)
		{write(STDOUT_FILENO, env[stat], _strlen(env[stat]));
		write(STDOUT_FILENO, "\n", 1);
		}
		stat++;
	}
}
