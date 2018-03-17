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
	char **array;
	char *token;

	array = malloc(sizeof(char *) * 3);
	token = strtok(string," ");
	while (token != NULL)
	{
/*		write(STDOUT_FILENO, token, strlen(token));
		write(STDOUT_FILENO, "\n", 1);
*/		array[i] = token;
		i++;
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
	int i, j = 0;
	char **array;

	write(STDOUT_FILENO, "$ ", 2);
	characters = getline(&buffer, &bufsize, stdin);
	while (*(buffer + j) != '\n')
		j++;
	*(buffer + j) ='\0';

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
		printf("%s\n", array[i]);
	}

	free(buffer);
	return (0);
}
