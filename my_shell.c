#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char* input = NULL;
    size_t input_size = 0;

    while (1) {
        printf("SimpleShell> ");

        // Use getline to read user input
        ssize_t line_length = getline(&input, &input_size, stdin);

        if (line_length == -1) {
		printf("Exiting the shell\n");
    		free(input);
    		exit(EXIT_SUCCESS);
	}

        // Remove the newline character if it exists
        if (line_length > 0 && input[line_length - 1] == '\n') {
            input[line_length - 1] = '\0';
        }

        // Fork a child process
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            // Parse the input into arguments
            char* args[64];
            int arg_count = 0;
            char* token = strtok(input, " \t");
            while (token != NULL) {
                args[arg_count++] = token;
                token = strtok(NULL, " \t");
            }
            args[arg_count] = NULL;

            // Execute the command
            execvp(args[0], args);

            // If execvp fails, print an error message
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);

        }
    }

    free(input); // Free the dynamically allocated memory for input
    return 0;
}

