#include "shell.h"
/**
 * main - programe that handle a simple shell
 * @argc: number of parametre passed to programe
 * @argv: the list of parametre passed
 * Return: 0
*/
int main(int argc, char **argv)
{
	char command[128];
	int is_intercative = isatty(0);
	(void)argc;

	while (true)
	{
		if (is_intercative)
		{
			displayprompt();
			read_command(command, sizeof(command));
			exucuteCommand(command, argv);
		}
		else
		{
			read_command(command, sizeof(command));
			exucuteCommand(command, argv);
			displayprompt();
		}


	}
	return (0);
}
