#include "shell.h"

/**
 * 
 *
 *  
*/

ssize_t get_input(char* input,ssize_t input_size,int is_interactive)
{

ssize_t line_length;
line_length = getline(&input, &input_size, stdin);
        if (line_length == -1) 
        {
            if (!is_interactive && feof(stdin)) {
                void displayprompt();
                free(input);
                exit(EXIT_SUCCESS);
                return (-1);
            } else if (feof(stdin)) {
                my_print("\n");
                free(input);
                exit(EXIT_SUCCESS);
                return (-1);
            } else {
                perror("getline");
                free(input);
                exit(EXIT_FAILURE);
            }
        }
return (line_length);
}