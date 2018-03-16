#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	size_t characters;

	char *token;
	int i;
	char *array[2];

	write(STDOUT_FILENO, "$ ", 2);
	characters = getline(&buffer, &bufsize, stdin);

	token = strtok(buffer," ");
	while (token != NULL)
	{
		write(STDOUT_FILENO, token, strlen(token));
		if (*token == '\n')
			break;

		write(STDOUT_FILENO, "\n", 1);
		token = strtok(NULL, " ");
	}

/*	write(STDOUT_FILENO, buffer, bufsize); */

	free(buffer);
	return (0);
}
