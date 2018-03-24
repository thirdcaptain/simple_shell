#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name)
{
        int i = 0, j = 0, k = 0;
        char *str;

        while (*environ)
        {
                i = 0;
                j = 0;
                while (name[i] != '\0' && (*environ)[j] != '=')
                {
                        if (name[i] == (*environ)[j])
                        {
                                i++;
                                j++;
                        }
                        else
                        {
                                break;
                        }
                }
                if ((*environ)[j] == '=' && name[i] == '\0')
                        break;
                (*environ)++;
        }

        j++;
        str = malloc(sizeof(char) * 1024);
        if (str == NULL)
                return (NULL);
         while ((*environ)[j] != '\0')
        {
                str[k] = (*environ)[j];
                j++;
                k++;
        }
        str[k] = '\0';
        return (str);
}

char **print_dir(char *str)
{
        int i = 0;
        char **array;
        char *token;
        array = malloc(sizeof(char *) * 20);
        token = strtok(str, ":");
        while (token != NULL)
        {
                array[i] = token;
                i++;
                token = strtok(NULL, ":");
        }
        array[i + 1] = NULL;
        return (array);
}

char **strings(char **path, char *name)
{
	int namelen = 0, pathlen = 0, i = 0, j = 0, k = 0, lengths = 0;
	char *tmp;

	while (name[namelen] != '\0')
		namelen++;

	while (path[j] != NULL)
	{
		i = 0;
		j = 0;
		pathlen = 0;

		while ((*path)[pathlen] != '\0')
		{
			pathlen++;
		}
		lengths = pathlen + namelen;
	
		tmp = malloc(sizeof(char) * lengths + 2);
		if (tmp == NULL)
			return (NULL);

		for(i = 0; i < pathlen; i++)
		{
			tmp[i] = path[j][i];
		}
		i++;
		tmp[i] = "/";
		i++;
		while (name[k] != '\0')
		{
			tmp[i] = name[k];
			k++;
			i++;
		}
		tmp[i + 1] = '\0';
	}
	printf("%s\n", tmp);
	return (tmp);
}

int main(void)
{
        int i = 0;
        char *str;
        char **str2;

        str = _getenv("PATH");
        printf("%s\n", str);
        str2 = print_dir(str);
        for (i = 0; str2[i] != NULL; i++)
        {
                printf("%s\n", str2[i]);
        }
        free(str);
        return (0);
}
