#include "main.h"

/**
 * _getline - puts input from user into buffer line
 * @fp: buffer for user input
 * Return: buffer with user input
 */
char *_getline(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = getline(&line, &len, fp);

	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
