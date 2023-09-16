#include "shell.h"
/**
 * create_path_list - function that split the path and store it in linked list
 * @path: the PATH of system
 * Return: Linked list of directories
*/
struct node *create_path_list(char *path)
{
	struct node *head = NULL;
	struct node *tail = NULL;
	char *dir = strtok(path, ":");
while (dir != NULL)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));

	new_node->dir = strdup(dir);
	new_node->next = NULL;
	if (head == NULL)
	{
	head = new_node;
	tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
	}
	dir = strtok(NULL, ":");
}
	return (head);
}
