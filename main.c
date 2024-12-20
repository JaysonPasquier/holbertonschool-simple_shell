#include <stdio.h>
#include <string.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Entry point for the shell program.
 * Displays a shell prompt and executes commands entered by the user.
 * Return: 0 on success, or exits with failure code on error.
 */
int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		display_prompt();

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("fgets");
			continue;
		}

		buffer[strcspn(buffer, "\n")] = '\0';
		if (strlen(buffer) == 0)
		{
			continue;
		}

		execute_command(buffer);
	}

	return (0);
}
