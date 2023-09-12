#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc,char **argv) {
    char* input = NULL;
    size_t input_size = 0;

    // Check if stdin is associated with a terminal (interactive mode)
    int is_interactive = isatty(STDIN_FILENO);

    while (1) {

        if (is_interactive) {
            printf("SimpleShell> ");
        }

        // Use getline to read user input
        ssize_t line_length = getline(&input, &input_size, stdin);
	
        if (line_length == -1) 
	{
        
		if (!is_interactive && feof(stdin))
		{
			printf("SimpleShell> ");
			free(input);
			exit(EXIT_SUCCESS);
                        return (-1);
		}
		else if (feof(stdin)) 
		{
                // Handle EOF (Ctrl+D) gracefully or exit
       			printf("\n");
		   	free(input);
           		exit(EXIT_SUCCESS);
			return (-1);
      		} 		
		else 
		{
               		perror("getline");
               		free(input);
                	exit(EXIT_FAILURE);
            	}
        }

        // Remove the newline character if it exists
        if (line_length > 0 && input[line_length - 1] == '\n') {
            input[line_length - 1] = '\0';
	}
        //copy the input
      
	// Fork a child process
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            free(input);
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
	{
            // Child procces
            // Parse the input into arguments
            char* args[64];
            int arg_count = 0;
	    char* token;

            token = strtok(input, " \t");
            while(token != NULL)
	    {
	    	args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " \t");
	    }

	    args[arg_count] = NULL;

            // Execu the command
            execve(args[0], args, NULL);


		if (errno == ENOENT && !is_interactive)
                 {
                        fprintf(stderr, "%s: 1: %s : not found\n", argv[0], args[0]);
                }

		else  if (errno == ENOENT) {
      	    		// Command not found
	   		 fprintf(stderr, "%s : No such file or directory\n", argv[0]);
		}

	    	 else 
	    	{
       		// If execvp fails, print an error message
            	        perror("execve");
           		free(input); // Freted memory for input
            		exit(EXIT_FAILURE);
        	} 
	}
	else{
           	 // Parent process
            	int status;
            	waitpid(pid, &status, 0);
	   }
    }
    free(input); // Free the dynamically allocated memory for input
    return 0;
}
