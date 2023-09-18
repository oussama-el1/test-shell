
#include "shell.h"

int main(int argc, char** argv) {
    int is_interactive;
	char* input = NULL;
    (void) argc;
   

    is_interactive = isatty(STDIN_FILENO);

    while (1) 
    {
     	print_prompt();  		


       input = get_user_input(is_interactive);

       myfunc(input);


	cret_procees(is_interactive, argv, input);
    }
    free(input);
    return 0;
}
