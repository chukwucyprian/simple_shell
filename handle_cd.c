#include "main.h"

/**
 * handle_cd - handles the cd command
 * @command: user command
 * @env: environment variables
 * Return: 1 if cd command was handled, 0 otherwise
 */
int handle_cd(char *command)
{
const char *cd_command = "cd";
size_t cd_len = strlen(cd_command);
char *arg;
/* Find the first non-space character */
while (*command == ' ')
command++;

/* Check if the command is "cd" */
if (strlen(command) >= cd_len && memcmp(command, cd_command, cd_len) == 0 &&
(command[cd_len] == ' ' || command[cd_len] == '\0'))
{
/* Extract the argument from the command */
arg = strtok(command + cd_len + 1, " ");

if (arg != NULL)
return (handle_cd_arg(arg));

return (handle_cd_no_arg());
}

return (0); /* Command was not the cd command */
}

/**
 * handle_cd_arg - handles the cd command with argument
 * @arg: argument of the cd command
 * Return: 1 if cd command was handled, 0 otherwise
 */
int handle_cd_arg(char *arg)
{
char prev_dir[100];
if (strcmp(arg, "-") == 0)
{
/* Change to the previous directory */
if (getenv("OLDPWD") == NULL)
{
write(STDERR_FILENO, "OLDPWD not set\n", strlen("OLDPWD not set\n"));
return (1);
}
arg = getenv("OLDPWD");
write(STDOUT_FILENO, arg, strlen(arg));
write(STDOUT_FILENO, "\n", 1);
}

/* Save the current directory as the previous directory */
if (getcwd(prev_dir, sizeof(prev_dir)) == NULL)
{
perror("getcwd");
return (1);
}

if (chdir(arg) != 0)
{
perror("chdir");
return (1);
}

if (setenv("PWD", getcwd(NULL, 0), 1) != 0)
{
perror("setenv");
return (1);
}

if (setenv("OLDPWD", prev_dir, 1) != 0)
{
perror("setenv");
return (1);
}

return (1); /* Command was the cd command */
}

/**
 * handle_cd_no_arg - handles the cd command without argument
 * Return: 1 if cd command was handled, 0 otherwise
 */
int handle_cd_no_arg(void)
{
char *home = getenv("HOME");
char prev_dir[100];
if (home == NULL)
{
write(STDERR_FILENO, "HOME not set\n", strlen("HOME not set\n"));
return (1);
}
if (getcwd(prev_dir, sizeof(prev_dir)) == NULL)
{
perror("getcwd");
return (1);
}

if (chdir(home) != 0)
{
perror("chdir");
return (1);
}
if (setenv("PWD", getcwd(NULL, 0), 1) != 0)
{
perror("setenv");
return (1);
}

if (setenv("OLDPWD", prev_dir, 1) != 0)
{
perror("setenv");
return (1);
}

return (1); /* Command was the cd command */
}

