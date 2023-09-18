#include "shell.h"
/**
 * _strtok - function that breaks the string into tokens
 * @str: string to be tokenize
 * @del: delimit strings char
 * Return: first/next token, otherwise null-pointer
 **/
char *_strtok(char *str, const char *del)
{
	static char *p;

	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + _strspn(p, del);
	p = str + _strcspn(str, del);
	if (p == str)
		return (p = 0);
	p = *p ? *p = 0, p + 1 : 0;
	return (str);
}
/**
 * _strcspn - function that computes the length of the string
 * @s1: string to check
 * @s2: string to compare
 * Return: length of the segment.
 **/
size_t _strcspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
			return (ret);
		s1++, ret++;
	}
	return (ret);
}
/**
 * _strspn - function that computes the length of the string
 * @s1: strint to compute the lengh
 * @s2: string delimit
 * Return: the length of the segment.
 **/
size_t _strspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1 && _strchr(s2, *s1++))
		ret++;
	return (ret);
}
/**
 * _strchr - function that locates the ﬁrst occurrence of char in the
 * string pointer
 * @s: string
 * @ch: character
 * Return: a pointer, otherwise a null pointer
 **/
char *_strchr(const char *s, int ch)
{
	while (*s != (char)ch)
		if (!*s++)
			return (0);
	return ((char *)s);
}
