#include "main.h"

/**
 * handle_exit - handles the exit command
 * @command: user command
 * Return: 1 if exit command was handled, 0 otherwise
 */
int handle_exit_status(char *command)
{
size_t exit_len = 4; /* Length of the "exit" command */
char *arg;

/* Find the first non-space character */
while (*command == ' ')
command++;
 /* Check if the command is "exit" */
if (command[0] == 'e' && command[1] == 'x'
		&& command[2] == 'i' && command[3] == 't' &&
(command[exit_len] == ' ' || command[exit_len] == '\0'))
{
exit(0); /* Exit the shell with status 0 */
}

/* Check if the command starts with "exit " */
if (command[0] == 'e' && command[1] == 'x' && command[2] == 'i'
		&& command[3] == 't' && command[exit_len] == ' ')
{
/* Extract the argument from the command */
arg = command + exit_len + 1;

/* Check if the argument is a valid integer */
if (*arg != '\0')
{
int status = 0;
while (*arg != '\0')
{
/* Check if the character is a digit */
if (*arg < '0' || *arg > '9')
return (0); /* Command is not valid */
status = status * 10 + (*arg - '0');
arg++;
}
exit(status); /* Exit the shell with the specified status */
}
}
return (0); /* Command was not the exit command */
}

