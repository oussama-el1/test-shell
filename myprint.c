#include "shell.h"
/**
 * my_print - function that print the output
 * @message: the argument that i want to print it
 * Return: nothing
*/
void my_print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}