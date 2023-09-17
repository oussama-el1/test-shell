#include "shell.h"

/**
 * 
 * 
 * 
*/

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
            fprintf(stderr, "allocation error\n");
            return NULL;
        }

        new_node->dir = strdup(token);
        if (new_node->dir == NULL) {
            fprintf(stderr, "strdup error\n");
            return NULL;
        }

        new_node->next = NULL;

        // Add to empty list
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