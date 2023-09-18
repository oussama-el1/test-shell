#include "shell.h"

void print_prompt() {
    int is_interactive = isatty(STDIN_FILENO);
    
    if (is_interactive) {
        write_message("SimpleShell> ");
    }
}
