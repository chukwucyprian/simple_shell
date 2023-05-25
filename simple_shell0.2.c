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
 * _free - deallocates memory
 * @com: string
 * Return: Nothing
 */
void _free(char *com)
{
	free(com);
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
	char *argv[10], *command = NULL;
	size_t len = 1;
	ssize_t nread, pid;
	struct stat buffer;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			signal(SIGINT, signal_handler);
			write(1, "$ ", 2);
		}
		nread = getline(&command, &len, stdin);
		if (nread == -1)
			_free(command);
		command = _remove(&command);
		if (command[0])
			if (space_track(command) == 1)
				command = space_handle(&command);
		if (command[0])
		{
			parse(command, argv);
			if (stat(argv[0], &buffer) == 0)
			{
				pid = fork();
				if (pid == -1)
					_free(command);
				else if (pid == 0)
				{
					execve(argv[0], argv, env);
					exit(0);
				}
				else
					wait(NULL);
			}
			else
				print_error(str);
		}
	}
}

