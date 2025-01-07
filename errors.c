#include "main.h"

/**
 * errors - prints errors based on case
 * @error: error number associated with perror statement
 * Return: void
 */
void errors(int error)
{
	switch (error)
	{
		case 126:
			write(STDERR_FILENO, "Permission denied\n", 18);
			break;
		case 127:
			write(STDERR_FILENO, "Command not found\n", 18);
			break;
		case 1:
		default:
			perror("Error");
			break;
	}
}
