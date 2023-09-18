#include "shell.h"

void myfunc(char *input)
{
	if (strcmp(input, "exit") == 0) 
	 {
            printf("Exiting the shell\n");
            free(input);
            exit(EXIT_SUCCESS);
        
	}
	if (strcmp(input, "env") == 0) 
	{
   		extern char** environ;
	        char** env = environ;
    		while (*env != NULL) 
		{
       			 printf("%s\n", *env);
        	       	 env++;
    		}
	}
}
