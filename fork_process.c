#include "shell.h"
/**
 * fork_process - creates a new process and execute within
 * @args: tokenized input (commands + arguments)
 * @argv: argv from main passed
 * @env: environment variables
 */

void fork_process(char **args, char **argv, char **env)
{
	pid_t my_pid;
	paths current_paths = handle_path(env, args);
	size_t i, flag;

	for (i = 0 ; i < current_paths.size ; i++)
	{
		if (access(current_paths.my_paths[i], X_OK) == 0)
		{
			my_pid = fork();
			if (my_pid == -1)
			{
				perror("Error happened\n");
				exit(EXIT_FAILURE);
			}
			if (my_pid == 0)
			{
				execve(current_paths.my_paths[i], args, env);
			}
			else
			{
				wait(NULL);
				break;
			}
		}
	}
	flag = access(current_paths.my_paths[i - 1], X_OK) != 0;
	if (i == current_paths.size && flag)
		perror(argv[0]);
	qol_free(current_paths.my_paths, current_paths.size);
}
