#include "shell.h"


int main(int argc, char** argv) {
    char *input = NULL;
    size_t input_size = 0;
    ssize_t line_length;
    pid_t pid = fork();
    int is_interactive = isatty(STDIN_FILENO);
    while (1)
    {
        if (is_interactive) {
            displayprompt();
        }
        line_length = get_input(input, input_size);
        removenline(line_length, input);
	
    exitshell(input);
    envglobal(input);
    void execute_c(pid, is_interactive, input, argv);
    }
free(input);
return 0;
}