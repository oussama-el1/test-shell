#include "shell.h"

/**
 * 
 * 
 * 
*/

void envglobal(char* input)
{

extern char** environ;
char** env = environ;

if (strcmp(input, "env") == 0) 
	{
    	while (*env != NULL) 
		{
       			printf("%s\n", *env);
        	    env++;
    		}
	}
}