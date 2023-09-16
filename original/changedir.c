#include "shell.h"

/**
 *dir- Method to change directory
 *@myargs: Method to change directory
 *Return: returns 0 on success
 */
int dir(char *myargs[])
{
	if (!myargs[1])
	{
		chdir(getenv("HOME"));
		return (1);
	}
	else
	{
		if (chdir(myargs[1]) == -1)
		{
			write(1, myargs[1], _strlen(myargs[1]));
			write(1, ",does not exist", 16);
			return (-1);
		}
	}
	return (0);
}
