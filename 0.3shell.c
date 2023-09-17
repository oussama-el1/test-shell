#include "shell.h"


list* creation_list() {
    char* path;
    char* token;
    list* head = NULL;
    list* tail = NULL;
    list* new_node;

    path = getenv("PATH");

    token = strtok(path, ":");

    while (token != NULL) {
        new_node = (list*)malloc(sizeof(list));
        if (new_node == NULL) {
            fprintf(stderr, "allocation error\n");
            return NULL;
        }

        new_node->dir = strdup(token);
        if (new_node->dir == NULL) {
            fprintf(stderr, "strdup error\n");
            return NULL;
        }

        new_node->next = NULL;

        // Add to empty list
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        token = strtok(NULL, ":");
    }
    return head;
}

void free_list(list* head) 
{

	while (head != NULL) 
	{
	      	 list* temp = head;
      	  	 head = head->next;
       	  	 free(temp->dir);
       	 	 free(temp);
        }

}

int main(int argc, char** argv) {
    char* input = NULL;
    size_t input_size = 0;
    list* mylist = creation_list();

    // Check if stdin is associated with a terminal (interactive mode)
    int is_interactive = isatty(STDIN_FILENO);

    while (1) {
        if (is_interactive) {
            printf("SimpleShell> ");
        }

        // Use getline to read user input
        ssize_t line_length = getline(&input, &input_size, stdin);

        if (line_length == -1) {
            if (!is_interactive && feof(stdin)) {
                printf("SimpleShell> ");
                free(input);
                free_list(mylist);  // Free the linked list
                exit(EXIT_SUCCESS);
                return (-1);
            } else if (feof(stdin)) {
                // Handle EOF (Ctrl+D) gracefully or exit
                printf("\n");
                free(input);
                free_list(mylist);  // Free the linked list
                exit(EXIT_SUCCESS);
                return (-1);
            } else {
                perror("getline");
                free(input);
                free_list(mylist);  // Free the linked list
                exit(EXIT_FAILURE);
            }
        }


        // Remove the newline character if it exists
        if (line_length > 0 && input[line_length - 1] == '\n') {
            input[line_length - 1] = '\0';
        }

	 if (strcmp(input, "exit") == 0) 
	 {
            printf("Exiting the shell\n");
            free(input);
            // Free the memory allocated for the list
            free_list(mylist);
            exit(EXIT_SUCCESS);
        }


        // Fork a child process
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            free(input);
            free_list(mylist);  // Free the linked list
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            // Parse the input into arguments
            char* args[64];
            int arg_count = 0;
            char* token;

            token = strtok(input, " \t");
            while (token != NULL) {
                args[arg_count] = token;
                arg_count++;
                token = strtok(NULL, " \t");
            }

            args[arg_count] = NULL;

            // Test if it's a path
            if (args[0][0] == '/') {
                execve(args[0], args, NULL);
            } else {
                char fpath[256];
                list* cour;
                cour = mylist;
                while (cour != NULL) {
                    snprintf(fpath, sizeof(fpath), "%s/%s", cour->dir, args[0]);
                    execve(fpath, args, NULL);
                    cour = cour->next;
                }
            }

            // Handle errors if execve fails
            if (errno == ENOENT && !is_interactive) {
                fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
            } else if (errno == ENOENT) {
                // Command not found
                fprintf(stderr, "%s: %s: No such file or directory\n", argv[0], args[0]);
            } else {
                // If execve fails, print an error message
                perror("execve");
            }
            free(input); // Free memory for input
            free_list(mylist);  // Free the linked list
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }
    // Free the dynamically allocated memory for input and linked list
    free(input);
    free_list(mylist);
    return 0;
}

