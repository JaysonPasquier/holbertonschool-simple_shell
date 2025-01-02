#include "main.h"

/**
 * _which - searches directories in PATH variable for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *_which(char *command, char *fullpath, char *path)
{
	char *path_copy, *token;
	unsigned int command_length, path_length, original_path_length;

	command_length = _strlen(command);
	original_path_length = _strlen(path);

	path_copy = malloc(sizeof(char) * (original_path_length + 1));
	if (!path_copy)
		return (errors(3), NULL);

	_strcpy(path_copy, path);
	token = strtok(path_copy, ":");

	while (token)
	{
		path_length = _strlen(token);
		fullpath = malloc(sizeof(char) * (path_length + command_length + 2));
		if (!fullpath)
		{
			free(path_copy);
			return (errors(3), NULL);
		}

		_strcpy(fullpath, token);
		fullpath[path_length] = '/';
		_strcpy(fullpath + path_length + 1, command);
		fullpath[path_length + command_length + 1] = '\0';

		if (access(fullpath, X_OK) == 0)
			break;

		free(fullpath);
		fullpath = NULL;
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (fullpath);
}
