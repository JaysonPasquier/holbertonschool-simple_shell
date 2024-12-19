#include "main.h"

/**
 * exec_with_path - Function to execute a command with a given path
 * @path: The path to the executable file
 * @argv: Arguments for the command
 *
 * This function creates a new process using fork and executes the command
 * with execve if the path is valid.
 */

void exec_with_path(char *path, char *argv[])
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(path, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
