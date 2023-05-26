#include "main.h"
/**
 * parse - parses a string
 * @str: string
 * @argv: array of parsed strings
 * Return: array of strings
 */
char **parse(char *str, char *argv[])
{
	char *ptr = str;
	size_t i = 0;

	argv[i] = strtok(ptr, " ");
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	return (argv);
}
/**
 * _prompt - displays prompt
 * Return: Nothing
 */
void _prompt(void)
{
	signal(SIGINT, signal_handler);
	write(1, "$ ", 2);
}
/**
 * com_location - Finds command location
 * @cmpt: command path
 * @com: command
 * @path: path
 * @env: environmental variables
 * Return: Nothing
 */
void com_location(char *cmpt, char *com, char *path, char **env)
{
	new_string(cmpt, com);
	_path(env, &path);
	_locate(&cmpt, path);
}
/**
 * com_test - tests a user given command
 * @argv: array of command and arguments
 * @envir: environmental variables
 * Return: nothing
 */
void com_test(char *argv[], char **envir)
{
	execve(argv[0], argv, envir);
	exit(0);
}
/**
 * _execute - executes the user given command
 * @str: arguments
 * @env: Environmental variables
 * Return: nothing
 */
void _execute(char *str, char **env)
{
	char *argv[10], *command = NULL, *cmpth, *path;
	size_t len = 1;
	ssize_t nread, pid;

	cmpth = malloc(100);
	memory_error(cmpth);
	path = malloc(100);
	memory_error(path);
	cmpth[0] = '\0';
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_prompt();
		nread = getline(&command, &len, stdin);
		if (nread == -1)
			multi_free(command, cmpth, path);
		command = _remove(&command);
		if (command[0])
			if (space_track(command) == 1)
				command = space_handle(&command);
		if (cmpth[0])
			empty_string(&cmpth);
		if (command[0])
			com_location(cmpth, command, path, env);
		if (cmpth[0])
		{
			_append(cmpth, command);
			parse(cmpth, argv);
			pid = fork();
			if (pid == -1)
				_free(command);
			else if (pid == 0)
				com_test(argv, env);
			else
				wait(NULL);
		}
		if (cmpth[0] == '\0' && command[0])
			print_error(str);
	}
}

