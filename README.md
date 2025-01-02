# Simple Shell Project

## Description

This project is a simple UNIX command line interpreter implemented in C. It aims to replicate basic functionalities of the sh shell, providing a hands-on understanding of how shells work, process creation, and command execution in Unix-like operating systems.

## Table of Contents
1. [Features](#features)
2. [Requirements](#requirements)
3. [Compilation](#compilation)
4. [Usage](#usage)
5. [Built-in Commands](#built-in-commands)
6. [Files](#files)
7. [Key Functions](#key-functions)
8. [Flowchart](#flowchart)
9. [Resources](#resources)
10. [List of Allowed Functions](#list-of-allowed-functions)
11. [Authors](#authors)
12. [Acknowledgments](#acknowledgments)
13. [License](#license)

## Features

- Displays a prompt "$ " and waits for user input
- Executes simple shell commands
- Handles command lines with arguments
- Implements built-in commands: exit, env, setenv, unsetenv
- Handles the PATH to find executable programs
- Supports interactive and non-interactive modes
- Handles the EOF (End Of File) condition
- Handles the Ctrl + C signal without exiting the shell

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler with flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Follow Betty style guidelines
- No more than 5 functions per file
- All header files should be include guarded
- Use system calls only when necessary

## Compilation

To compile the shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode

```bash
./hsh
#cisfun$ /bin/ls
hsh main.c shell.c
#cisfun$ exit
```

### Non-Interactive Mode

```bash
echo "/bin/ls" | ./hsh
```

## Built-in Commands

- `exit`: Exit the shell
- `env`: Print the current environment
- `setenv`: Set an environment variable
- `unsetenv`: Unset an environment variable

## Files

- `_which.c` Implements the functionality to search for executable files in the directories listed in the PATH environment variable.
- `builtin_execute.c` Contains the logic to execute built-in shell commands.
- `builtins.c` Defines the built-in commands supported by the shell (e.g., exit, env).
- `child.c` Handles the creation and management of child processes for executing external commands.
- `errors.c` Manages error handling and error message display.
- `free.c` Contains functions for memory deallocation and cleanup.
- `getenv.c` Implements custom functions to interact with environment variables.
- `getline.c` Provides a custom implementation of the getline function for reading user input.
- `hsh.c` The main shell loop that reads commands and executes them.
- `main.h` Header file containing function prototypes and necessary includes.
- `prompt.c` Handles the display of the shell prompt.
- `tokenizer.c` Splits the input string into tokens for command processing.
- `utility_functions.c` Contains various utility functions used throughout the shell implementation.

## Key Functions

- `_putchar`: Prints a character
- `_puts`: Prints a string
- `_strlen`: Calculates the length of a string
- `_strdup`: Duplicates a string
- `concat_all`: Concatenates three strings

## Flowchart

![Flowchart](/img/flowchart-simple-shell.png)


## Resources

- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

## List of Allowed Functions

access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, printf, fprintf, vfprintf, sprintf, putchar, read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid, wait3, wait4, write, and all functions from string.h

## Authors

[Your Name]
[Your Partner's Name]

## Acknowledgments

This project was completed as part of the Holberton School curriculum. Special thanks to:

- Ken Thompson, the creator of the original Unix operating system, the Thompson shell, and the B programming language
- Dennis Ritchie, co-creator of the Unix operating system and creator of the C programming language

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Citations:
- [1] https://en.wikipedia.org/wiki/Thompson_shell
- [2] https://cvw.cac.cornell.edu/linux/shells/environment-variables
- [3] https://www.invent.org/inductees/ken-thompson
- [4] https://www.baeldung.com/linux/path-variable
- [5] https://en.wikipedia.org/wiki/Ken_Thompson_(programmer)