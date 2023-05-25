#include "main.h"
/**
 * total_spaces - computes string's number of spaces
 * @str: string
 * Return: total number of spaces in a string
 */
size_t total_spaces(char *str)
{
	size_t spaces = 0, i = 0;

	while (str[i])
	{
		if (str[i] == ' ')
			spaces++;
		i++;
	}
	return (spaces);
}
/**
 * end_spaces - deletes spaces at the end
 * @str: string
 * Return: String with no spaces at the end
 */
char *end_spaces(char **str)
{
	char *ptr = *str;
	size_t a;

	a = _strlen(ptr);
	a--;
	if (ptr[a] == ' ')
	{
		while (ptr[a] == ' ')
		{
			ptr[a] = '\0';
			a--;
		}
	}
	return (ptr);
}
/**
 * space_track - checks spaces in a string
 * @str: string
 * Return: 1 (space found) 0 (no spaces)
 */
size_t space_track(char *str)
{
	size_t i = 0, len = 0;

	if (str[0] == ' ')
		return (1);
	while (str[len])
		len++;
	len = len - 1;
	if (str[len] == ' ')
		return (1);
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			return (1);
		i++;
	}

	return (0);
}
/**
 * space_handle - eliminates spaces in a string
 * @str: string of characters
 * Return: space free string
 */
char *space_handle(char **str)
{
	char *ptr = *str, strc[100];
	size_t i = 0, k = 0, spaces, len;

	len = _strlen(ptr);
	spaces = total_spaces(ptr);
	if (spaces == len)
		empty_string(&ptr);
	if (ptr[0])
		end_spaces(&ptr);
	while (ptr[i])
	{
		if (ptr[i] != ' ')
			strc[k++] = ptr[i];
		if (ptr[i] == ' ' && i == 0)
		{
			while (ptr[i] == ' ')
				i++;
			strc[k++] = ptr[i];
		}
		if (ptr[i] == ' ')
		{
			if (ptr[i + 1] != ' ')
			{
				strc[k] = ptr[i];
				k++;
			}
		}
		i++;
	}
	strc[k] = ptr[i];
	len--;
	while (ptr[len])
	{
		ptr[len] = strc[0];
		if (len == 1)
			break;
		len--;
	}
	_strdup(&ptr, strc);
	return (ptr);
}

