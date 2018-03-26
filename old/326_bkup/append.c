#include "header.h"

char *append(char *path, char *name)
{
        int namelen = 0, pathlen = 0, i = 0, j = 0, k = 0, lengths = 0;
        char *tmp;

        while (name[namelen] != '\0')
                namelen++;

                i = 0;
                j = 0;
                pathlen = 0;

                while (path[pathlen] != '\0')
                {
                        pathlen++;
                }
                lengths = pathlen + namelen;

                tmp = malloc(sizeof(char) * lengths + 2);
                if (tmp == NULL)
                        return (NULL);

                for(i = 0; i < pathlen; i++)
                {
                        tmp[i] = path[i];
                }
                tmp[i] = '/';
                i++;
                while (name[k] != '\0')
                {
                        tmp[i] = name[k];
                        k++;
                        i++;
                }
                tmp[i + 1] = '\0';

        return (tmp);
}

