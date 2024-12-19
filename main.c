#include "main.h"

/**
 * main - Entry point of the shell program
 *
 * This function implements a simple shell that continuously prompts the user
 * for input, processes the input, and executes commands.
 * It handles user input,
 * parses commands, and calls the `execute_command` function to process them.
 * The shell will exit when the user types "exit".
 *
 * Return: 0 on successful completion, exits with status 0 on exit command.
 */

int main(void)
{
	char *cmd = NULL;
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);

		if (getline(&cmd, &len, stdin) == -1)
			break;

		cmd[strcspn(cmd, "\n")] = '\0';

		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(0);
		}

		execute_command(cmd);

		free(cmd);
		cmd = NULL;
		len = 0;
	}

	return (0);
}
