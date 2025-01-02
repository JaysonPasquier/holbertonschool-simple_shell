#include "main.h"
/**
**shell_exit - exits the shell
**Return: void
**/

int shell_exit(void)
{
	return (-1);
}

int shell_env(void)
{
	for (int i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
