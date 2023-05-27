#include "main.h"

/**
 * handle_cd - handles the cd command
 * @command: user command
 *
 * Return: 1 if cd command was handled, 0 otherwise
 */
int handle_cd(char *command)
{char cwd[4096];
char *arg = command + 3; /* Skip "cd " in the command */
/* Check if no argument is provided, use $HOME */
if (arg[0] == '\0' || (arg[0] == '~' && arg[1] == '\0'))
{
char *home = getenv("HOME");
if (home == NULL)
{write(STDERR_FILENO, "cd: $HOME not set\n", 18);
return (1);
}
arg = home;
} /* Check if the argument is "-" */
if (strcmp(arg, "-") == 0)
{
char *oldpwd = getenv("OLDPWD");
if (oldpwd == NULL)
{
write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
return (1);
}
arg = oldpwd;
} /* Change directory using chdir */
if (chdir(arg) == -1)
{char *error_message;
if (errno == ENOENT)
error_message = "cd: No such file or directory\n";
else
error_message = "cd: Error changing directory\n";
write(STDERR_FILENO, error_message, strlen(error_message));
return (1);
} /* Update PWD and OLDPWD environment variables */
if (getcwd(cwd, sizeof(cwd)) == NULL)
{write(STDERR_FILENO, "cd: Error retrieving current directory\n", 38);
return (1);
}
setenv("PWD", cwd, 1);
setenv("OLDPWD", getenv("PWD"), 1);
return (0);
}

