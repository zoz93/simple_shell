#include "shell.h"
/**
 * handle_exit - exit the program with a specific status
 * @status: status number
 * @env: enviroment var
 */

void handle_exit(int status, char **env)
{
	(void)env;
	exit(status);
}

/**
 * handle_env - print the enviroment var
 * @status: not used var
 * @env: enviroment var
 */

void handle_env(int status, char **env)
{
	int x = 0;

	for (; env[x] ; x++)
	{
		write(STDOUT_FILENO, env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(void)status;
}

