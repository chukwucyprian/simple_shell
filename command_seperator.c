#include "main.h"


/**
 * get_program_name - Extracts the program name from the command string
 * @command: Command string
 *
 * Return: Program name string
 */
char *get_program_name(char *command)
{
char *program_name;
size_t i, len;

len = strlen(command);
program_name = malloc((len + 1) * sizeof(char));
if (program_name == NULL)
return (NULL);

for (i = 0; command[i] != '\0' && command[i] != ' '; i++)
program_name[i] = command[i];

program_name[i] = '\0';
return (program_name);
}

/**
 * concat_strings - Concatenates two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: Concatenated string
 */
char *concat_strings(char *str1, char *str2)
{
size_t len1 = strlen(str1);
size_t len2 = strlen(str2);
char *result = malloc((len1 + len2 + 1) * sizeof(char));
size_t i;
size_t j;

if (result == NULL)
return (NULL);

for (i = 0; i < len1; i++)
result[i] = str1[i];

for (j = 0; j < len2; j++)
result[i + j] = str2[j];

result[i + j] = '\0';
return (result);
}

/**
 * print_error_message - prints the error message
 * @command: command that caused the error
 * @error_msg: error message to be printed
 *
 * Return: Nothing
 */
void print_error_message(char *command, char *error_msg)
{
char *prog_name = get_program_name(command);
char *msg = concat_strings(prog_name, error_msg);
write(STDERR_FILENO, msg, _strlen(msg));
free(prog_name);
free(msg);
}


/**
 * execute_single_command - executes a single command
 * @command: command string
 * @env: Environmental variables
 * Return: Nothing
 */
void execute_single_command(char *command, char **env)
{
char *argv[10];
struct stat buffer;
pid_t pid;
parse(command, argv);
if (stat(argv[0], &buffer) == 0)
{
pid = fork();
if (pid == -1)
free(command);
else if (pid == 0)
{
execve(argv[0], argv, env);
exit(0);
}
else
wait(NULL);
}
else
print_error_message(argv[0], command);
}

/**
 * execute_command - executes the user given command
 * @command: command string
 * @env: Environmental variables
 * Return: Nothing
 */
void execute_command(char *command, char **env)
{
char *ptr = command;
char *separator;
char *cmd;
char *argv[10];
while (1)
{
if (isatty(STDIN_FILENO))
{
signal(SIGINT, signal_handler);
write(1, "$ ", 2);
}
separator = command;
while (*separator != '\0' && *separator != ';')
separator++;
if (*separator == ';')
{*separator = '\0';
cmd = ptr;
ptr = separator + 1;
}
else
{
cmd = ptr;
ptr = NULL;
}
cmd = _remove(&cmd);
if (cmd[0])
{
if (space_track(cmd) == 1)
cmd = space_handle(&cmd);
if (cmd[0])
{
parse(cmd, argv);
execute_single_command(cmd, env);
}
}
if (separator == NULL)
break;
}
}

