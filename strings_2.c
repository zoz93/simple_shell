#include "shell.h"

int num_len(int num);
int _atoi(char *str);
char *_itoa(int num);
int _strcmp(char *s1, char *s2);

/**
 * num_len - Counts the digit length of a number.
 * @num: The number to measure.
 *
 * Return: The digit length.
 */

int num_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}
/**
 * _atoi - convert string to int
 * @str: string
 * Return: intger converted from string
 */

int _atoi(char *str)
{
	int i, num;
	int len = _strlen(str);

	if (str[0] >= '0' && str[0] <= '9')
		num = str[0] - '0';
	else
		return (0);
	for (i = 1; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num *= 10;
			num += str[i] - '0';
		}
		else
			return (0);
	}
	return (num);
}

/**
 * _itoa - Converts an integer to a string.
 * @x: The integer.
 *
 * Return: The converted string.
 */

char *_itoa(int x)
{
	char *buffer;
	int len = num_len(x);
	unsigned int num1;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);

	buffer[len] = '\0';

	if (x < 0)
	{
		x = x * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = x;
	}

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buffer);
}

/**
 * _strcmp - a function that compares two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: 15 or -15 or 0.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
