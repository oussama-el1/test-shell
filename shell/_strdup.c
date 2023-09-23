#include "shell.h"
/**
 * _strdup - Custom implementation of strdup that duplicates a string.
 * @str: The input string to be duplicated.
 * Return: A pointer to a newly allocated duplicate string.
 */
char *_strdup(const char *str)
{
	char *duplicate;
	size_t length = 0;
	size_t i;

	while (str[length] != '\0')
	{
		length++;
	}

	duplicate = (char *)malloc((length + 1) * sizeof(char));

	if (duplicate != NULL)
	{
		for (i = 0; i <= length; i++)
		{
			duplicate[i] = str[i];
		}
	}

	return (duplicate);
}
