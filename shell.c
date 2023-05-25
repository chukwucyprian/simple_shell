#include "main.h"

/* Function declarations */
void execute_interactive(char **env);
void execute_non_interactive(char **env, char *str);
void handle_command(char *command, char **env);
void execute_command(char *command, char **env);
void print_error_message(char *executable, char *command);

/**
 * _execute - executes the user given command
 * @str: arguments
 * @env: Environmental variables
 * @interactive: flag indicating interactive mode
 * Return: nothing
 */
void _execute(char *str, char **env, int interactive)
{
if (interactive)
{
signal(SIGINT, signal_handler);
execute_interactive(env);
}
else
{
execute_non_interactive(env, str);
}
}
/**
 * execute_interactive - Executes the shell in interactive mode.
 * @env: The array of environmental variables.
 */
void execute_interactive(char **env)
{
char *command = NULL;
size_t len = 1;
ssize_t nread;

while (1)
{
write(STDOUT_FILENO, "$ ", 2);
nread = getline(&command, &len, stdin);
if (nread == -1)
{
free(command);
exit(0);
}

command = _remove(&command);
if (command[0])
handle_command(command, env);
}
}
/**
 * execute_non_interactive - Executes the shell in non-interactive mode.
 * @env: The array of environmental variables.
 * @str: The command string to execute.
 */
void execute_non_interactive(char **env, char *str)
{
char *command = str;

if (str == NULL)
exit(0);

command = _remove(&command);
if (command[0])
handle_command(command, env);
}

/**
 * handle_command - Handles the execution of a command.
 * @command: The command string to execute.
 * @env: The array of environmental variables.
 */
void handle_command(char *command, char **env)
{
struct stat buffer;

if (stat(command, &buffer) == 0)
execute_command(command, env);
else
print_error_message(command, command);
}

/**
 * execute_command - Executes the given command.
 * @command: The command string to execute.
 * @env: The array of environmental variables.
 */
void execute_command(char *command, char **env)
{
pid_t pid;
char *argv[2];
argv[0] = command;
argv[1] = NULL;

pid = fork();
if (pid == -1)
exit(0);
else if (pid == 0)
{
execve(argv[0], argv, env);
print_error_message(argv[0], command);
exit(127);
}
else
wait(NULL);
}

/**
 * print_error_message - Prints the error message for a command not found.
 * @program_name: The name of the shell program.
 * @command: The command string.
 */
void print_error_message(char *program_name, char *command)
{
size_t len = 0;

len += write(STDERR_FILENO, program_name, _strlen(program_name));
len += write(STDERR_FILENO, ": 1: ", 5);
len += write(STDERR_FILENO, command, _strlen(command) - 1);
len += write(STDERR_FILENO, ": not found\n", 12);

(void)len;
}
