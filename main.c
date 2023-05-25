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
		_execute(argv[0], env, 1);
	return (0);
}

