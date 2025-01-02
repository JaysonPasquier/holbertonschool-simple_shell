#include "main.h"

/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
	size_t name_len = _strlen((char *)name);

	for (int i = 0; environ[i]; i++)
	{
		if (_strncmp((char *)name, environ[i], name_len) == 1)
		{
			char *equal_sign = strchr(environ[i], '=');

			if (equal_sign)
			{
				char *value = equal_sign + 1;

				if (*value == '\0')
				{
					errors(4);
					exit(EXIT_FAILURE);
				}

				char *path = malloc(_strlen(value) + 1);

				if (!path)
				{
					errors(3);
					return (NULL);
				}
				return (_strcpy(path, value));
			}
		}
	}

	return (NULL);
}
