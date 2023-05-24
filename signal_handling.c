#include "main.h"
/**
 * signal_handler - handling SIGINT signal
 * @signal: signal
 * Return: Nothing
 */
void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		;
	}
}
/**
 * print_error - Displays wrong command error message
 * @str: First main argument
 * Return: Nothing
 */
void print_error(char *str)
{
	char *buffer = ": No such file or directory\n";
	char error_message[40];
	size_t i = 0, k = 0, len;

	while ((error_message[i] = str[i]))
		i++;
	while ((error_message[i++] = buffer[k++]))
		;
	error_message[i] = buffer[k];

	len = _strlen(error_message);

	write(2, error_message, len);
}

