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
 * multi_free - It frees multi strings
 * @com: user inputted command
 * @cmpt: command location
 * @path: path
 * Return: Nothing
 */
void multi_free(char *com, char *cmpt, char *path)
{
	free(cmpt);
	free(path);
	free(com);
	exit(0);
}
/**
 * memory_error - Checks memory allocation error
 * @str: string
 * Return: Nothing
 */
void memory_error(char *str)
{
	if (str == NULL)
	{
		perror("memory allocation error");
		exit(0);
	}
}

