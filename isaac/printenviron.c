#include <stdio.h>

extern char **environ;

int main(void)
{
	int i = 0, k = 0;
	char *str;
	str = "PATH";
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		printf("%c", *environ[0]);
		printf("%c", *environ[1]);
		printf("%c", *environ[2]);
		printf("%c", *environ[3]);
		printf("%c", *environ[4]);
		printf("%c", *environ[5]);
		printf("%c", *environ[6]);
		printf("\n");
		i = 0;
		if (*environ[i] == str[i])
		{
/*			printf("%c", str[i]);
			printf("COW\n");
			while (*environ[i] == str[i])
			{
				printf("%c", str[i]);
				i++;
			}
*/
			printf("WE HAVE A MATCH\n");
			for (k = 0; *environ[k] != '\0'; k++)
			{
				printf("%c", *environ[k]);
			}
			printf("\n");
		}
/*
		while (1)
		{
			if (str[i] == '\0')
			{
				printf("WE HAVE A MATCH!");
				break;
			}
			else if (*environ[i] == str[i])
			{
				printf("%c", str[i]);
				printf("COW\n");
			}
			else
				break;
			i++;
		}
*/
		*environ++;
	}

	return(0);
}
