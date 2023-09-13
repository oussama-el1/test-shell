#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>
void my_print(const char *message);
void displayprompt(void);
void exucuteCommand(char *command, char **argv);
void read_command(char *command, size_t size);

#endif
