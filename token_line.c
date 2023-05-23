#include "shell.h"

/**
 * token_line - function to tokenize the input.
 * @line: the buffer line read to be tokenized.
 * @delim: the delimeter used
 * Return: pointer to array of strings.
 */

char **token_line(char *line, char *delim)
{
	char *token = NULL, *line_dup = NULL;
	char **tokens = NULL;
	int idx = 0, len = 0, number = 0;
	size_t size = (tokens_count(line, delim) + 1);

	len = _strlen(line);
	line_dup = _calloc(len + 1, sizeof(char));
	line_dup = _strdup(line);
	tokens = allocate_string_array(size);
	if (!tokens)
	{
		write(STDERR_FILENO, "Allocation Error\n", 17);
		exit(EXIT_FAILURE);
	}
	if (line_dup != NULL)
		token = strtok(line_dup, delim);
	while (token != NULL)
	{
		number = _strlen(token);
		tokens[idx] = malloc(sizeof(char) * (number + 1));
		if (!tokens[idx])
		{
			qol_free(tokens, idx);
			write(STDERR_FILENO, "Allocation Error\n", 17);
			exit(EXIT_FAILURE);
		}
		_strcpy(tokens[idx], token);
		idx++;
		token = strtok(NULL, delim);
	}
	tokens[idx] = NULL;
	free(line_dup);
	return (tokens);
}
