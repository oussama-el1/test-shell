#include "shell.h"
/**
 * displayprompt - function that diplay prompt
 * Return: nothing
*/
void displayprompt(void)
{
	int is_intercative = isatty(0);

	if (is_intercative)
	my_print("Shell$>");
}
