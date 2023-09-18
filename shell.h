#ifndef SHELL_FUNCTIONS_H
#define SHELL_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

typedef struct list {
    char* dir;
    struct list* next;
} list;

void print_prompt();
void myfunc(char *input);
char* get_user_input(int is_interactive);
void write_message(const char* message);
list* creation_list();
void free_list(list* head);
void cret_procees(int is_interactive, char **argiv, char* input);

#endif /* SHELL_FUNCTIONS_H */
