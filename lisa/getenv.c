#include <stdio.h>
#include <unistd.h>

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;
	char *str;

	while (*environ)
	{
		i = 0;
		j = 0;
		while (name[i] != '\0' && *environ[j] != '=')
		{
			if (name[i] == *environ[j])
			{
				printf("%c\n", name[i]);
				printf("%c\n", *environ[j]);
				i++;
				j++;
			}
			else
			{
				break;
			}
		}
		*environ++;
	}
	printf("%s\n", *environ);

	*environ++;
	while (*environ[j] != '\0')
	{
		str[k] = *environ[j];
		j++;
		k++;
	}
	printf("%s", str);
	return (str);

}

int main(void)
{
	_getenv("PATH");
	return (0);
}
