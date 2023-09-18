#include "shell.h"
/**
 * myfunc - function that handle the env and exit
 * @input: the input user
*/
void myfunc(char *input)
{
	if (strcmp(input, "exit") == 0)
	{
		printf("Exiting the shell\n");
		free(input);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(input, "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
