#include "shell.h"

char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);

/**
 * _strcpy - a function that copies the string pointed to by src
 * @dest: first input array
 * @src: string input
 *
 * Return: returns dest array
 */

char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - function that returns pointer to duplicated string
 * @str: the string that will be duplicated
 * Return: pointer to char
 */

char *_strdup(char *str)
{
	int size, i;
	char *ptr = NULL;

	if (!str)
		return (NULL);
	for (size = 0 ; str[size] != '\0' ; size++)
		;
	ptr = malloc((size + 1) * sizeof(*str));

	if (ptr == NULL)
		return (NULL);
	for (i = 0 ; i < size ; i++)
		ptr[i] = str[i];
	ptr[size] = '\0';
	return (ptr);
}

#include "shell.h"

/**
 * _strlen -  a function that returns the length of a string.
 * @s: input parameter pointer to char
 * Return: returns the length of the provided string
 */

int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	if (*s != '\0')
		return (1 + _strlen(s + 1));
	return ('\n');
}

/**
 * _strcat - function to concatenate two strings.
 * @dest: first string and the destination
 * @src: second string that will be concatenated
 *
 * Return: returns the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int x;

	while (dest[i])
		i++;
	for (x = 0 ; x < i && src[x] != '\0' ; x++)
		dest[i + x] = src[x];
	dest[i + x] = '\0';
	return (dest);
}

