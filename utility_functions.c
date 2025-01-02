#include "main.h"

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length of name
 * Return: 0 if strings are equal, 1 if they are not, -1 if lengths differ
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length = _strlen(variable);

	if (var_length != length)
		return (-1);

	for (unsigned int i = 0; name[i] != '\0' && variable[i] != '\0'; i++)
	{
		if (name[i] != variable[i])
			return (1);
	}
	return (0);
}

/**
 * _strncmp - compares two strings up to given length
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
	for (unsigned int i = 0; i < length; i++)
	{
		if (name[i] != variable[i])
			return (-1);
	}
	return (1);
}

/**
 * _strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int length = _strlen(src);

	for (i = 0; i <= length; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
