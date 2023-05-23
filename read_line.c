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
			exit(EXIT_SUCCESS);
		}
		perror("Error reading input\n");
		free(buff);
		exit(EXIT_FAILURE);
	}
	history++;
	if (buff[0] == '\0')
	{
		free(buff);
		return (NULL);
	}
	buff[read - 1] = '\0';
	return (buff);
}

