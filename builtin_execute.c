#include "main.h"
/**
**builtin_execute - executes the built in functions
**@tokens: arguments being passed
**Return: tokens
**/
int builtin_execute(char **tokens)
{
	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (!tokens[0])
		return (1);

	for (int i = 0; builtin[i].name; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, _strlen(tokens[0])) == 0)
			return (builtin[i].p());
	}
	return (1);
}
