#include "shell.h"
/**
 * exucuteCommand - create a child process and exucute the command
 * @command: the input user
 * @argv: the parametre passed to programe
 */
void exucuteCommand(char *command, char **argv)
{
	char *path;
	char *args[64];

	int intercative = isatty(0);
	__pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(command);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		int arg_count = 0;
		char *token;

		token = strtok(command, " \t");
		while (token)
		{
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " \t");
		} args[arg_count] = NULL;
		if (args[0][0] == '/')
		{
			withoutpath(args, argv, intercative);
		} path = getenv("PATH");
		if (path)
		{
			withpath(path, intercative, args, argv);
		}
		free(command);
	}
	else
	{
		int status;

		waitpid(child_pid, &status, 0);
	}
}
