#include "shell.h"

void removenline(size_t line_length,char* input)
{
    if (line_length > 0 && input[line_length - 1] == '\n') 
    {
        input[line_length - 1] = '\0';
    }
}