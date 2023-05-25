#include "main.h"
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
	char *argv[2] = {NULL, NULL}, *command = NULL;
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
			if (stat(command, &buffer) == 0)
			{
				argv[0] = command;
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

