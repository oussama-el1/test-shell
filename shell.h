#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * 
 * 
 * 
*/

typedef struct list {
    char* dir;
    struct list* next;
} list;

list* creation_list();
void free_list(list* head);
void displayprompt();
ssize_t get_input(input, input_size);
void my_print(const char *message);
void removenline(size_t line_length,char* input);
void exitshell(char* input);
void envglobal(char* input);
void execute_c(pid_t pid, int is_interactive, char* input);


#endif