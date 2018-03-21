#include <stdio.h>

char **environ;

int find_str(char *name)
{
	int i;

	while (*environ != NULL)
	{
		i = 0;
		while (name[i] != '\0')
		{
			if (name[i] == *environ[i])
				i++;

			else if (name[i] == '\0')
				return (1);

			else
				break;
		}
		*environ++;
	}
	return (0);
}

int main (void)
{
	char *string;
	int return_value;

	string = "PATH";
	return_value = find_str(string);

	printf("%d\n", return_value);
	return (0);
}
