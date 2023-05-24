#include "shell.h"
/**
 * read_line - function to read the input from STDIN
 * @flag: value used to detect when to print the new line
 * Return: the string that was read successfully.
 */
char *read_line(int flag)
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
			if (flag)
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		free(buff);
		exit(EXIT_FAILURE);
	}
	if (_strcmp(buff, "\n") != 0)
		buff[read - 1] = '\0';
	return (buff);
}

