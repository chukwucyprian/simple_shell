#include "main.h"
/**
 * _remove - removes the newline character
 * @str: string
 * Return: modified string
 */
char *_remove(char **str)
{
	char *ptr = *str;
	size_t i = 0;

	while (ptr[i])
	{
		if (ptr[i] == '\n')
			ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
/**
 * _strlen - computes string's length
 * @str: string
 * Return: string length
 */
size_t _strlen(char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
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
	char *argv[] = {NULL, NULL}, *command = NULL;
	size_t len = 1;
	ssize_t nread, pid;
	struct stat buffer;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			signal(SIGINT, signal_handler);
			write(1, "Shell$ ", 7);
		}
		nread = getline(&command, &len, stdin);
		if (nread == -1)
			_free(command);
		command = _remove(&command);
		if (command[0] != '\0')
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

