#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

extern char **environ;

void exec_with_path(char *path, char *argv[]);
void execute_command(char *cmd);

#endif /* MAIN_H */
