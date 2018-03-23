#include <stdio.h>
#include <stdlib.h>

/**
* prints environment line by line with string
*/
extern char **environ;

int main (void)
{

	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}

	/*
	printf("PATH: %s\n", getenv("PATH"));
	*/
	return (0);
}
