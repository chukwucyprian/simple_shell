#include "main.h"
/**
 * handle_env - handles shell env variables
 * @com: user given command
 * @envir: environmental variable
 * Return: nothing
 */
void handle_env(char *com, char **envir)
{
	char *compare = "env";
	size_t i = 0, k = 0, len;

	while (com[i] != '\0')
	{
		if (com[i] == compare[i])
			k++;
		i++;
	}
	if (k == 3 && (com[k] == '\0'))
	{
		i = 0;
		while (envir[i] != NULL)
		{
			len = _strlen(envir[i]);
			write(1, envir[i], len);
			write(1, "\n", 1);
			i++;
		}
	}
}

