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
		flag = access(current_paths.my_paths[i], X_OK);
		if (flag == 0)
		{
			my_pid = fork();
			if (my_pid == -1)
			{
				perror(argv[0]);
				free(current_paths.my_paths);
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
	qol_free(current_paths.my_paths);
	if (flag == (size_t)-1)
		perror("./shell");
}

