#include "main.h"

/**
 * errors - prints errors based on case
 * @error: error number associated with perror statement
 * Return: void
 */
void errors(int error)
{
	const char *error_message;

	switch (error)
	{
	case 1:
		error_message = ERR_FORK;
		break;
	case 2:
		perror("Error");
		return;
	case 3:
		error_message = ERR_MALLOC;
		break;
	case 4:
		error_message = ERR_PATH;
		break;
	default:
		return;
	}

	if (error != 2)
	{
		write(STDERR_FILENO, error_message, _strlen(error_message));
		if (error == 1)
			perror("Error");
	}
}
