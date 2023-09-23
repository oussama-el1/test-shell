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
	int is_intercative = isatty(0);
	(void)argc;

	while (true)
	{
		displayprompt();
		command = get_user_input(is_intercative);
		myfunc(command);
		exucuteCommand(command, argv);
	}
	free(command);
	return (0);
}
