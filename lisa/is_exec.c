#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

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


char *is_exec(char **path, char *name)
{
	char *str;
	int ret_stat;

	while (*path)
	{
		str = append(*path, name);
		if (access(str, F_OK) != -1)
			return (str);
		else
			path++;
	}
	return ("File doesn't exist or it hit null");
}

int main(void)
{
	char *path[] = {"/bin", "/tmp", NULL};
	char *name = "pwd";
	char *str;

	str = is_exec(path, name);
	printf("%s\n", str);
}
