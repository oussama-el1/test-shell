#include "shell.h"
/**
 * _strchr - function that searches for a character in a string.
 *
 * @str: The string in which to search for the character.
 * @ch: The character to search for.
 * Return: A pointer to the first occurrence, or NULL if not found.
 */
char *_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}

	if (ch == '\0')
	{
		return ((char *)str);
	}

	return (NULL);
}
