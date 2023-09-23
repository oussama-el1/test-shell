#include "shell.h"
/**
 * free_list - function that free Linked list
 * @head: the list
 * Return: nothing
*/
void free_list(struct node *head)
{
	struct node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->dir);
		free(temp);
	}
}
