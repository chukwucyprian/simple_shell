#include "main.h"
/**
 * handle_exit - handles exit
 * @com: user given command
 * Return: 1 (exit) 0 (continue)
 */
size_t handle_exit(char *com)
{
	char *str = "exit";
	size_t i = 0, k = 0;

	_remove(&com);
	if (com[0] != '\0')
	{
		if (space_track(com) == 1)
			space_handle(&com);
		while (str[i])
		{
			if (com[i] == str[i])
				k++;
			i++;
		}
		if (k == 4 && (com[k] == '\0' || com[k] == ' '))
			return (1);
	}
	return (0);
}

