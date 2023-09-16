#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>
/**
 * struct node - creating node to store the paths
 * @dir: pointer to directory in PATH
 * @next: pointer to next node
*/
struct node
{
	char *dir;
	struct node *next;
};
void my_print(const char *message);
void displayprompt(void);
void exucuteCommand(char *command, char **argv);
void read_command(char *command, size_t size);
struct node *create_path_list(char *path);

#endif
