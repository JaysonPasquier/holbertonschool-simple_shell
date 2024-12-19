#include "main.h"

/**
 * execute_command - Executes a command after parsing it
 * @cmd: The command to be executed
 *
 * This function parses the input command, checks if it's an absolute path,
 * or if it's found in the directories specified in `path_list`. It then
 * calls the `exec_with_path` function to execute the command.
 */

void execute_command(char *cmd)
{
	char *argv[MAX_ARGS];
	char *token;
	int argc = 0;
	char *path_list[] = {
		"/usr/local/sbin", "/usr/local/bin", "/usr/sbin", "/usr/bin", "/sbin",
		"/bin",
		NULL
	};
	int i, command_found = 0;

	token = strtok(cmd, " ");
	while (token != NULL && argc < MAX_ARGS - 1)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;

	if (argv[0][0] == '/')
	{
		exec_with_path(argv[0], argv);
		return;
	}
	for (i = 0; path_list[i] != NULL; i++)
	{
		char full_path[MAX_CMD_LEN];

		snprintf(full_path, sizeof(full_path), "%s/%s", path_list[i], argv[0]);

		if (access(full_path, X_OK) == 0)
		{
			command_found = 1;
			exec_with_path(full_path, argv);
			break;
		}
	}
	if (!command_found)
		fprintf(stderr, "%s: command not found\n", argv[0]);
}
