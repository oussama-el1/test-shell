#include "shell.h"
/**
 * get_user_input- Read the input user
 * @is_interactive: mode intercative with my shell
 * Return: input user
*/
char *get_user_input(int is_interactive)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t line_length;

	line_length = getline(&input, &input_size, stdin);

	if (line_length == -1)
	{
		if (!is_interactive && feof(stdin))
		{
			my_print("Shell$>");
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (feof(stdin))
		{
			my_print("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(input);
			exit(EXIT_FAILURE);
		}
	}

	if (line_length > 0 && input[line_length - 1] == '\n')
	{
		input[line_length - 1] = '\0';
	}

	return (input);
}
