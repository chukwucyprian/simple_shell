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

	while (str[i])
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

