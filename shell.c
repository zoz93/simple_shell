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
	int exit_status = 0, flag = 0;

	signal(SIGINT, my_signal);
	if (argc > 1)
	{
		perror("Here non-inter");
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
			flag = 1;
		}
		buff = read_line(flag);
		if (_strcmp(buff, "\n") == 0)
		{
			free(buff);
			continue;
		}
		tokens = token_line(buff, " ");
		free(buff);
		exit_status = tokens[1] ? _atoi(tokens[1]) : 0;
		funptr = find_fun(tokens[0]);
		if (funptr != NULL)
		{
			if (_strcmp(tokens[0], "exit") == 0)
				qol_free(tokens);
			funptr(exit_status, env);
		}
		else if (tokens != NULL)
			fork_process(tokens, argv, env);
		qol_free(tokens);
	}
}

/**
 * my_signal - handle ctrl + c
 * @sign: signal to handle
 */
void my_signal(int sign)
{
	if (sign == SIGINT)
		printf("\n$ ");
	fflush(stdout);
}

