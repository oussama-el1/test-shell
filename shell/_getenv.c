#include "shell.h"
/**
 * _getenv - Custom implementation of getenv
 * @name: The name of the environment variable to retrieve
 * Return: A pointer variable if found, or NULL if not found
 */
char *_getenv(char *name)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, _strlen(name)) == 0)
		{
			return (_strchr(*env, '=') + 1);
		}
	}
	return (NULL);
}
