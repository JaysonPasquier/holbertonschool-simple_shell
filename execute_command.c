#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * execute_command - Forks and executes a command.
 * @buffer: Command entered by the user.
 */
void execute_command(char *buffer)
{
	pid_t pid;
	char *args[2];

	args[0] = buffer;
	args[1] = NULL;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		execve(buffer, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
}
