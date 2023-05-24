#include "shell.h"

/**
 * main - our own shell entry point
 * @argc: number of arguments passed
 * @argv: array of strings with commands+arguments
 * @env: env variables
 *
 * Return: 0
 */

int main(int argc, char *argv[], char **env)
{
	char *buff = NULL;
	char **tokens;
	void (*funptr)(int, char **);
	int exit_status = 0;

	if (argc > 1)
	{
		perror("Here non-inter");
	}
	while (1)
	{
		if (!isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "", 0);
		else if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		buff = read_line();
		if (buff == NULL)
			continue;
		tokens = token_line(buff, " ");
		exit_status = tokens[1] ? _atoi(tokens[1]) : 0;
		funptr = find_fun(tokens[0]);
		if (funptr != NULL)
			funptr(exit_status, env);
		else if (tokens != NULL)
			fork_process(tokens, argv, env);
		free(buff);
	}
	exit(EXIT_FAILURE);
}
