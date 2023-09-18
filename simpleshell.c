#include "shell.h"
/**
 * main - programe that handle a simple shell
 * @argc: number of parametre passed to programe
 * @argv: the list of parametre passed
 * Return: 0
*/
int main(int argc, char **argv)
{
	char *command = NULL;
	size_t command_size;
	ssize_t line_length;
	int is_intercative = isatty(0);
	(void)argc;

	command_size = 0;
	while (true)
    {
        if (is_intercative)
        {
            displayprompt();
        }
		line_length = getline(&command, &command_size, stdin);
        if (line_length == -1)
        {
            if (!is_intercative && feof(stdin))
            {
				displayprompt();
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
                my_print("Error when reading input\n");
                free(command);
                exit(EXIT_FAILURE);
            }
        }
		command[strcspn(command, "\n")] = '\0';
        if (strcmp(command, "exit") == 0)
        {
            my_print("exit shell\n");
            free(command);
            exit(EXIT_SUCCESS);
        }

        if (strcmp(command, "env") == 0)
        {
            char **env = environ;
            while (*env != NULL)
            {
                my_print(*env);
                my_print("\n");
                env++;
            }
        }
        exucuteCommand(command, argv);
    }

    free(command);
    return (0);
}
