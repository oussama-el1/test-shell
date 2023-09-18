#include "shell.h"


void write_message(const char* message) {
    write(STDOUT_FILENO, message, strlen(message));
}
