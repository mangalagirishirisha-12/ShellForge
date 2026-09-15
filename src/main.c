#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/input.h"

int main()
{
    char *line;

    printf("=================================\n");
    printf("ShellForge Version 2.0\n");
    printf("=================================\n");

    while(1)
    {
        printf("myshell> ");

        line = read_line();

        if(strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        if(strlen(line) != 0)
            printf("You entered : %s\n", line);

        free(line);
    }

    printf("Goodbye!\n");

    return 0;
}
