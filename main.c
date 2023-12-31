#include "shell.h"
/**
 * main - main arguments functions
 * @c:count of argumnents
 * @av: arguments
 * @env: environment
 * Return: _exit = 0.
 */
int main(int c, char **av, char **env)
{
	char *va = NULL;
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _ext = 0, n = 0;
	(void) c;
	while (1)
	{
		getcommand = shellprompt();
		if (getcommand)
		{
			pathValue++;
			user_command = _get_token(getcommand);
			if (!user_command)
			{
				free(getcommand);
				continue;
			}
			if ((!_strcmp(user_command[0], "exit")) && user_command[1] == NULL)
				_exits(user_command, getcommand, _ext);
			if (!_strcmp(user_command[0], "env"))
				_getenv(env, va);
			if (!_strcmp(user_command[0], "cd"))
				dir(user_command);
			else
			{
				n = path_separate(&user_command[0], env);
				_ext = _fork(user_command, av, env, getcommand, pathValue);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_ext);
		}
		free(getcommand);
	}
	return (_ext);
}
