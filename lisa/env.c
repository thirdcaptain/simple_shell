#include <stdio.h>

int main(int ac, char **av, char **env)
{
	int i = 0;

	while (*qenv[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
