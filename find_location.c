#include "main.h"
/**
 * _modify - modifies the given command
 * @str: path
 * @cha: charecter
 * @str1: command
 * Return: Appended path
 */
char *_modify(char **str, char cha, char *str1)
{
	size_t i = 0, j = 0;
	char *ptr = *str;

	while (ptr[i] != '\0')
		i++;
	ptr[i++] = cha;
	while ((ptr[i] = str1[j]) != '\0')
	{
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/**
 * _path - finds the path
 * @envr: enrironmental variables
 * @pth: path
 * Return: path string
 */
char *_path(char **envr, char **pth)
{
	char *spath = "PATH=", *strpath = *pth, *ptr;
	size_t i = 0, k = 0, cmp = 0;

	while (envr[i])
	{
		ptr = envr[i];
		if (ptr[0] == 'P' && ptr[1] == 'A')
		{
			while (ptr[k])
			{
				if (ptr[k] == spath[k])
				{
					cmp++;
					k++;
				}
				if (cmp == k && cmp == 5)
				{
					cmp = 0;
					while ((strpath[cmp++] = ptr[k++]))
						;
					break;
				}
				if (k != cmp)
				{
					k = 0;
					cmp = 0;
					break;
				}
			}
		}
		if (cmp > 5)
			break;
		i++;
	}
	return (strpath);
}
/**
 * _locate - gets command's location
 * @com: command
 * @path: path
 * Return: Location (success) NULL (failure)
 */
char *_locate(char **com, char *path)
{
	char *pathptr, scpy[500], *tok_str, *ptr;
	char *tmp;
	struct stat buffer;
	size_t i = 0, j = 0;

	ptr = *com;
	if (stat(ptr, &buffer) == 0)
		return (ptr);
	if (ptr)
	{
		pathptr = path;
		tmp = malloc(100);
		while ((scpy[i] = pathptr[i]) != '\0')
			i++;
		scpy[i] = '\0';
		tok_str = strtok(scpy, ":");
		while (tok_str != NULL)
		{
			i = 0;
			while ((tmp[i] = tok_str[i]) != '\0')
				i++;
			tmp = _modify(&tmp, '/', ptr);
			if (stat(tmp, &buffer) == 0)
			{
				while ((ptr[j] = tmp[j]) != '\0')
					j++;
				free(tmp);
				return (ptr);
			}
			tok_str = strtok(NULL, ":");
		}
		free(tmp);
	}
	empty_string(&ptr);
	return (ptr);
}
/**
 * new_string - Fills a string with new contents
 * @str: string
 * @command: user inputted command
 * Return: Modified string
 */
char *new_string(char *str, char *command)
{
	char *ptr = str;
	size_t k = 0;

	while ((ptr[k] = command[k]) != ' ')
	{
		k++;
		if (command[k] == '\0')
			break;
	}
	ptr[k] = '\0';
	return (ptr);
}

