#include "main.h"
/**
 * main - tests our shell
 * @argc: Number of arguments
 * @argv: arguments
 * @env: Environmental variables
 * Return: Always 0
 */
int main(int argc, char *argv[], char **env)
{
	if (argc == 1)
		_execute(argv[0], env);
	return (0);

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: cd DIRECTORY\n", 20);
		return (1);
	}
	if (handle_cd(argv[1]) != 0)
	{
		return (1);
	}
	return (0);
}


