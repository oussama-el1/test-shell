#include "shell.h"
/**
 * read_command - read the input of user
 * @command: the input user
 * @size: size of command
*/
void read_command(char *command, size_t size)
{
	extern char **environ;
	int intercative = isatty(0);

	if (fgets(command, size, stdin) == NULL)
	{
		if (!intercative && feof(stdin))
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		else if (feof(stdin))
		{
			my_print("\n");
			free(command);
			exit(EXIT_SUCCESS);
		}
		else
		{
			my_print("Error when reading input \n");
			free(command);
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
	if (strcmp(command, "exit") == 0)
	{
		my_print("exit shell\n");
		exit(EXIT_SUCCESS);
	}
	if (strcmp(command, "env") == 0)
	{
		char **env;

		env = environ;
		while (*env != NULL)
		{
			my_print(*env);
			my_print("\n");
			env++;
		}
	}
}
