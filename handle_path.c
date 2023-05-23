#include "shell.h"

/**
 * handle_path - tokenizes the path received to array of strings
 * @env: env variables received from main
 * @tokens_args: tokenized user input arguments
 * Return: stuct with array of strings + it's size
 */

paths handle_path(char **env, char **tokens_args)
{
	char *full_path = get_path(env), *old_path_token = NULL, *temp;
	int count = tokens_count(full_path, ":"), i;
	char **path_tokens = token_line(full_path, ":"), **extra_path;
	paths current_paths;

	extra_path = malloc((count + 1) * sizeof(char *));
	for (i = 0 ; i < count ; i++)
	{
		old_path_token = path_tokens[i];
		temp = malloc(_strlen(old_path_token) + _strlen(tokens_args[0]) + 2);
		_strcpy(temp, old_path_token);
		_strcat(temp, "/");
		_strcat(temp, tokens_args[0]);
		extra_path[i] = temp;
	}
	extra_path[count] = malloc(_strlen(tokens_args[0]) + 1);
	_strcpy(extra_path[count], tokens_args[0]);
	current_paths.my_paths = extra_path;
	current_paths.size = count + 1;
	return (current_paths);
}

