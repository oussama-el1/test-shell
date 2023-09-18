#include "shell.h"

void free_list(list* head) 
{
    while (head != NULL) {
        list* temp = head;
        head = head->next;
        free(temp->dir);
        free(temp);
    }
}


list* creation_list() {
    char* path;
    char* token;
    list* head = NULL;
    list* tail = NULL;
    list* new_node;

    path = getenv("PATH");

    token = strtok(path, ":");

    while (token != NULL) {
        new_node = (list*)malloc(sizeof(list));
        if (new_node == NULL) {
            write_message("allocation error\n");
            return NULL;
        }

        new_node->dir = strdup(token);
        if (new_node->dir == NULL) {
            write_message("strdup error\n");
            return NULL;
        }

        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        token = strtok(NULL, ":");
    }
    return head;
}
