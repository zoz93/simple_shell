#include "shell.h"

/**
 * tokens_count - count the number of tokens within a string >> "/bin/ls -l -p"
 * @str: the string to be parsed
 * @delim: the delimeter to check for
 *
 * Return: returns the number of tokens within a string
 */

int tokens_count(char *str, char *delim)
{
	int tokens = 0, len, index = 0;

	len = _strlen(str);
	for (; index < len ; index++)
	{
		if (str[index] == *delim)
		{
			tokens++;
		}
	}
	return (tokens + 1);
}

/**
 * qol_free - Frees up memory taken by char **.
 * @args: double pointer containing commands/arguments.
 */

void qol_free(char **args)
{
	size_t x;

	for (x = 0 ; args[x] != NULL ; x++)
		free(args[x]);

	free(args);
}

/**
 * find_fun - checks if it's a builting function
 * @str: command to be checked
 * Return: a function pointer to the selected function
 * or NULL instead
 */

void (*find_fun(char *str))()
{
	int x = 0;
	f_struc my_funcs[] = {
		{"printenv", handle_env},
		{"exit", handle_exit},
		{NULL, NULL}
	};

	while (my_funcs[x].command)
	{
		if (str != NULL && _strcmp(str, my_funcs[x].command) == 0)
			return (my_funcs[x].funptr);
		x++;
	}
	return (NULL);
}

/**
 * _calloc - function that allocates mmemory for array
 * @nmemb: number of elements
 * @size: size of bytes for each element
 * Return: returns pointer to the allocated memory
 */

void *_calloc(size_t nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i = nmemb * size;
	unsigned int j;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(i);
	if (ptr == NULL)
		return (NULL);
	for (j = 0 ; j < i ; j++)
		((char *)ptr)[j] = 0;
	return (ptr);
}

/**
 * allocate_string_array - function that allocates mmemory for array of strings
 * @n: number of elements
 * Return: returns pointer to the allocated memory
 */

char **allocate_string_array(size_t n)
{
	size_t i = 0;
	char **array = _calloc(n, sizeof(char *));

	if (array == NULL)
		return (NULL);
	for (; i < n ; i++)
		array[i] = NULL;
	return (array);
}

