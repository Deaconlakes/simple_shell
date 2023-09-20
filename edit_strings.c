#include "shell.h"
/**
 * _strcat - function that copy string to another string.
 * @dest: char input
 * @src: char src
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int d = 0;
	int s = 0;

	for (d = 0; dest[d] != '\0'; d++)
	{
	}

	for (s = 0; src[s] != '\0'; s++, d++)
	{
		dest[d] = src[s];
	}

	dest[d] = '\0';
		return (dest);
}
/**
 * _strcmp - funtion that compare the values of a string
 * @s1: string pointer
 * @s2: string pointer
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	int len_s1 = _strlen(s1);
	int len_s2 = _strlen(s2);

	for (a = 0; a < len_s1 && a < len_s2; a++)
	{
		if (s1[a] != s2[a])
			return ((int)s1[a] - s2[a]);
	}
	return (0);
}
/**
 * _strlen - funtion copies the string pointed to by src into dest
 * @s: pointer character
 * Return: char pointer to dest
 */
int _strlen(char *s)
{
	int ch = 0;

	while (*(s + ch) != '\0')
	{
		ch++;
	}

	return (ch);
}
/**
 * _strncmp -  function that compares two strings.
 * @s1: string one
 * @s2: string two
 * @n: number of characters
 * Return: difference
 */
size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * _strcpy - function that  copies the string pointed to by src
 * @dest: destination of the copy
 * @src: pointer to souce to be copy
 * Return: char pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);
	return (dest);
}
