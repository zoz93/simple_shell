#include "shell.h"

/**
 * get_path - get path from environment
 * @env: environment variables
 * Return: PATH value
 */

char *get_path(char **env)
{
	int len = 0;
	char *Path = NULL, *full_path = NULL;

	Path = getenv("PATH");
	if (!Path)
		return (NULL);
	len = _strlen(Path);
	full_path = malloc(sizeof(char) * (len + 1));
	if (!full_path)
		return (NULL);
	full_path = _strcpy(full_path, Path);
	return (full_path);
	(void)env;
}

