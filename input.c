#include "shell.h"

char* get_user_input(int is_interactive)
{
    char* input = NULL;
    size_t input_size = 0;
    ssize_t line_length;

    line_length = getline(&input, &input_size, stdin);

    	if (line_length == -1) 
        {
            if (!is_interactive && feof(stdin)) {
                write_message("SimpleShell> ");
                free(input);
                exit(EXIT_SUCCESS);
            } else if (feof(stdin)) {
                write_message("\n");
                free(input);
                exit(EXIT_SUCCESS);
         
            } else {
                perror("getline");
                free(input);
                exit(EXIT_FAILURE);
            }
        }


    if (line_length > 0 && input[line_length - 1] == '\n') {
        input[line_length - 1] = '\0';
    }

    return input;
}
