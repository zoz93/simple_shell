#include "shell.h"
/**
 * read_line - function to read the input from STDIN
 * Return: the string that was read successfully.
 */
char *read_line(void)
{
	char *buff = NULL;
	size_t len;
	ssize_t  read;

	read = getline(&buff, &len, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			free(buff);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		free(buff);
		exit(EXIT_FAILURE);
	}
	if (_strcmp(buff, "\n") != 0)
		buff[read - 1] = '\0';
	return (buff);
}

