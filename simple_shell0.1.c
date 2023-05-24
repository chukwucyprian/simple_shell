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
 * _append - appends a string
 * @str1: First string
 * @buffer: Append characters
 * Return: Appended string
 */
char *_append(char **str1, char *buffer)
{
	char *ptr = *str1;
	size_t i, j = 0;

	i = _strlen(ptr);

	while ((ptr[i] = buffer[j]) != '\0')
	{
		i++;
		j++;
	}
	ptr[i] = buffer[j];
	return (ptr);
}
/**
 * _free - deallocates memory
 * @com: string
 * Return: Nothing
 */
void _free(char *com)
{
	free(com);
	write(1, "\n", 1);
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
	char *buffer = ": No such file or directory\n";
	char *error_message;
	size_t len = 1;
	ssize_t nread, pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "Shell$ ", 7);
		nread = getline(&command, &len, stdin);
		if (nread == -1)
		{
			free(command);
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			exit(0);
		}
		command = _remove(&command);
		if (command[0] != '\0')
		{
			argv[0] = command;
			pid = fork();
			if (pid == -1)
				_free(command);
			else if (pid == 0)
			{
				if (execve(argv[0], argv, env) == -1)
				{
					error_message = _append(&str, buffer);
					write(2, error_message, _strlen(error_message));
				}
				free(command);
				exit(0);
			}
			else
				wait(NULL);
		}
	}
}

