#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * returns array for each word of a string received from getline
 *
 */

char **ret_array(char *string)
{
	int i = 0;
	char *array[2];
	char *token;

	token = strtok(string," ");
	while (token != NULL)
	{
		write(STDOUT_FILENO, token, strlen(token));
		write(STDOUT_FILENO, "\n", 1);
		array[i] = token;
		token = strtok(NULL, " ");
	}
	return (array);
}

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

/*
	token = strtok(buffer," ");
	while (token != NULL)
	{
		write(STDOUT_FILENO, token, strlen(token));
		if (*token == '\n')
			break;

		write(STDOUT_FILENO, "\n", 1);
		token = strtok(NULL, " ");
	}
*/

/*	write(STDOUT_FILENO, buffer, bufsize); */

	array = ret_array(buffer);

	for (i = 0; i < 2; i++)
	{
		printf("%s", array[i]);
	}

	free(buffer);
	return (0);
}
