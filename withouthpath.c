#include "shell.h"
/**
 * withoutpath - when user put all the path
 * @args: where store the command after tokinization
 * @argv: the parametre passed to programme
 * @intercative: the mode of user connect with my shell
*/
void withoutpath(char **args, char **argv, int intercative)
{
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
