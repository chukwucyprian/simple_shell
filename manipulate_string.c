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
 * empty_string - deletes string contents
 * @str: string
 * Return: Empty string
 */
char *empty_string(char **str)
{
	size_t len;
	char *ptr = *str;

	len = _strlen(ptr);
	len--;
	while (ptr[len])
	{
		ptr[len] = '\0';
		if (len == 0)
			return (ptr);
		len--;
	}
	return (ptr);
}
/**
 * _strdup - duplicates a string
 * @strd: string dulpicate
 * @ostr: original string
 * Return: string duplicate
 */
char *_strdup(char **strd, char *ostr)
{
	char *ptr = *strd;
	size_t i = 0;

	while (ostr[i])
	{
		ptr[i] = ostr[i];
		i++;
	}
	ptr[i] = ostr[i];

	return (ptr);
}
/**
 * _append - appends a string
 * @str: First string
 * @buffer: Append characters
 * Return: Appended string
 */
char *_append(char *str, char *buffer)
{
	char *ptr = str;
	size_t i = 0, j = 0;

	i = _strlen(ptr);

	while (buffer[j] != '\0')
	{
		if (buffer[j] == ' ')
		{
			while (buffer[j] != '\0')
			{
				ptr[i] = buffer[j];
				i++;
				j++;
			}
			ptr[i] = buffer[j];
			return (ptr);
		}
		j++;
	}
	return (ptr);
}

