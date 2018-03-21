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

char *print_dir(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ':')
		{
			str[i] = '\n';
		}
		i++;
	}
	return (str);
}
int main(void)
{
        char *str;
	char *str2;

        str = _getenv("PATH");
	str2 = print_dir(str);
        printf("%s\n", str2);
	return (0);
}
