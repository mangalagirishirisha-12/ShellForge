#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../include/input.h"
#include "../include/parse.h"

int main()
{
    char *line;
    char **args;

    printf("=================================\n");
    printf("ShellForge Version 3.0\n");
    printf("=================================\n");

    while(1)
    {
        printf("myshell> ");

        line = read_line();
        args = parse_line(line);

        if(args[0] == NULL)
        {
            free(line);
            free(args);
            continue;
        }

        if(strcmp(args[0], "exit") == 0)
        {
            free(line);
            free(args);
            break;
        }

        pid_t pid = fork();

        if(pid == 0)
        {
            execvp(args[0], args);
            perror("Error");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }

        free(line);
        free(args);
    }

    return 0;
}
