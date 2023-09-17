#include "shell.h"

/**
 * 
 * 
 * 
*/

void exitshell(char* input)
{
    if (strcmp(input, "exit") == 0) 
	{
        my_print("Exiting the shell\n");
        free(input);
        exit(EXIT_SUCCESS);
	}
}