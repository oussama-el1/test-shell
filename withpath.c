#include "shell.h"
/**
 * withpath - exucute the command user when don't specific path
 * @path: path in system
 * @args: where we store the path after tokenizitaion
 * @intercative: mode where user intercat with shell
 * @argv: the parametre passed to programe
 * Return: nothing
*/
void withpath(char *path, int intercative, char **args, char **argv)
{
	struct node *path_list = create_path_list(path);
			struct node *current = path_list;

			while (current)
			{
				char *full_path = malloc(strlen(current->dir) + strlen(args[0]) + 2);

				sprintf(full_path, "%s/%s", current->dir, args[0]);
				execve(full_path, args, NULL);
				free(full_path);
				current = current->next;
			}
			free_list(path_list);
			if (!intercative)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			}
			else
			{
				fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			}
}
