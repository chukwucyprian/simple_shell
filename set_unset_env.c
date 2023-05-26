#include "main.h"

/**
 * handle_setenv - handles the setenv command
 * @command: user command
 * Return: 1 if setenv command was handled, 0 otherwise
 */
int handle_setenv(char *command)
{
const char *setenv_command = "setenv";
size_t setenv_len = strlen(setenv_command);
char *var, *value;
/* Find the first non-space character */
while (*command == ' ')
command++;

/* Check if the command is "setenv" */
if (strncmp(command, setenv_command, setenv_len) == 0 &&
command[setenv_len] == ' ')
{
/* Extract the variable and value from the command */
var = strtok(command + setenv_len + 1, " ");
value = strtok(NULL, " ");

if (var != NULL && value != NULL)
{
if (setenv(var, value, 1) != 0)
{
write(STDERR_FILENO, "Failed to set environment variable\n", 34);
}
}
else
{
write(STDERR_FILENO, "Invalid setenv command syntax\n", 30);
}

return (1); /* Command was the setenv command */
}

return (0); /* Command was not the setenv command */
}

/**
 * handle_unsetenv - handles the unsetenv command
 * @command: user command
 * Return: 1 if unsetenv command was handled, 0 otherwise
 */
int handle_unsetenv(char *command)
{
const char *unsetenv_command = "unsetenv";
size_t unsetenv_len = strlen(unsetenv_command);
char *var;

/* Find the first non-space character */
while (*command == ' ')
command++;

/* Check if the command is "unsetenv" */
if (strncmp(command, unsetenv_command, unsetenv_len) == 0 &&
command[unsetenv_len] == ' ')
{
/* Extract the variable from the command */
var = strtok(command + unsetenv_len + 1, " ");
if (var != NULL)
{
if (unsetenv(var) != 0)
{
write(STDERR_FILENO, "Failed to unset environment variable\n", 36);
}
}
else
{
write(STDERR_FILENO, "Invalid unsetenv command syntax\n", 31);
}

return (1); /* Command was the unsetenv command */
}

return (0); /* Command was not the unsetenv command */
}

