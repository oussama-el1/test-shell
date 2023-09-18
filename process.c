#include "shell.h" 

void cret_procees(int is_interactive, char **argv, char* input)
{


	pid_t pid = fork();
if (pid == -1) {
            perror("fork");
            free(input);
            exit(EXIT_FAILURE);
        }

if (pid == 0) {
                list* mylist = creation_list();
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

            if (errno == ENOENT && !is_interactive) {
                fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
            } else if (errno == ENOENT) {
                fprintf(stderr, "%s: %s: No such file or directory\n", argv[0], args[0]);
            } else {
                perror("execve");
            }
            free(input);
            free_list(mylist);
            exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
}
