#include "main.h"

/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
	char *variable, *equal_sign, *value;
	int compare;
	unsigned int path_length, length, i;
	char *path;

	length = _strlen((char *)name);
	i = 0;

	while (environ[i] != NULL)
	{
		variable = environ[i];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			equal_sign = strchr(variable, '=');
			if (equal_sign != NULL)
			{
				value = equal_sign + 1;

				if (value == NULL || *value == '\0')
				{
					errors(4);
					exit(EXIT_FAILURE);
				}

				path_length = _strlen(value);
				path = malloc(sizeof(char) * path_length + 1);
				if (path == NULL)
				{
					errors(3);
					return (NULL);
				}
				path = _strcpy(path, value);
				return (path);
			}
		}
		i++;
	}

	return (NULL);
}
