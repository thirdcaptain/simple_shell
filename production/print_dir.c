#include "header.h"

char **print_dir(char *str)
{
        int i = 0;
        char **array;
        char *token;

        array = malloc(sizeof(char *) * 20);
        if (array == NULL)
                return NULL;
        token = strtok(str, ":");
        while (token != NULL)
        {
                array[i] = token;
                i++;
                token = strtok(NULL, ":");
        }
        return (array);
}

