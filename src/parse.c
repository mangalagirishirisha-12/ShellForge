#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/parse.h"

#define TOKEN_SIZE 64

char **parse_line(char *line)
{
    int size = TOKEN_SIZE, position = 0;
    char **tokens = malloc(size * sizeof(char*));

    char *token = strtok(line, " ");

    while(token != NULL)
    {
        tokens[position++] = token;

        if(position >= size)
        {
            size *= 2;
            tokens = realloc(tokens, size * sizeof(char*));
        }

        token = strtok(NULL, " ");
    }

    tokens[position] = NULL;
    return tokens;
}
