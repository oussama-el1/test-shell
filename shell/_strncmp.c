#include "shell.h"
/**
 * _strncmp - function that compares two strings up to a specified length.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * @n: The maximum number of characters to compare.
 * Return: 0
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}

		if (*str1 == '\0')
		{
			return (0);
		}

		str1++;
		str2++;
		n--;
	}

	return (0);
}
