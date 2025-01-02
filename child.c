#include "main.h"

/**
 * child - function for child process
 * @fullpath: full path of executable
 * @tokens: tokenized user input
 * Return: 0 on success, -1 on failure
 */
int child(char *fullpath, char **tokens)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(fullpath, tokens, environ) == -1)
			return (-1);
	}
	else
	{
		int status;

		wait(&status);
	}

	return (0);
}
