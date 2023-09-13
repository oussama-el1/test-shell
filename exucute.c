#include "shell.h"
/**
 * exucuteCommand - create a child process and exucute the command
 * @command: the input user
*/
void exucuteCommand(char *command, char **argv)
{
	int intercative = isatty(0);

	__pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[64];
			int arg_count = 0;
			char *token;

			token = strtok(command, " \t");
			while (token)
			{
				args[arg_count] = token;
				arg_count++;
				token = strtok(NULL, " \t");
			}
			args[arg_count] = NULL;
		execve(args[0], args, NULL);
		if (errno == ENOENT && !intercative)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
		}
		else if (errno == ENOENT)
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		}
		else
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		
	}
	else
	{
		int status;

		waitpid(child_pid, &status, 0);
	}
}
