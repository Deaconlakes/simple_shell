#include "shell.h"

/**
 * _get_token - get token of string
 * @input: pointer to user input
 * Return: To a pointer
 */
char **_get_token(char *input)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (input == NULL)
		return (NULL);

	while (input[i])
	{
		if (input[i] == ' ')
			size++;
		i++;
	}
	if ((size + 1) == _strlen(input))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = _strtok(input, " \n\t\r");
	i = 0;
	while (token != NULL)
	{
		user_command[i] = token;
		token = _strtok(NULL, " \n\t\r");
		i++;
	}
	user_command[i] = NULL;
	return (user_command);
}
