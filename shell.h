#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;
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
struct node *create_path_list(char *path);
void free_list(struct node *head);
void myfunc(char *input);
char *get_user_input(int is_interactive);
void withpath(char *path, int intercative, char **args, char **argv);
void withoutpath(char **args, char **argv, int intercative);


#endif
