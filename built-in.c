#include "header.h"

/**
 * built_in - chops newline and executes exit and env built in functionality
 * @input: user input
 * @environment: array of environment strings
 *
 * Return: string with newline removed
 */

char *built_in(char *input, char **environment)
{
	int i = 0, k = 0;
	size_t length = 0;

	if (input == NULL)
	{
		perror("Invalid Input");
		exit(0);
	}
	while (*(input + i) != '\n')
		i++;
	*(input + i) = '\0';

	if (_strcmp(input, "exit") == 0 && input[0] != '\0')
	{
		exit(0);
	}
	if (_strcmp(input, "env") == 0 && input[0] != '\0')
	{
		while (*(environment + k) != NULL)
		{	
			length = _strlen(*(environment + k));
			write(STDOUT_FILENO, *(environment + k), length);
			write(STDOUT_FILENO, "\n", 1);
			k++;
		}
	}

	return (input);
}
