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
	int i = 0;
	int k = 0;

	if (input == NULL)
	{
		perror("Invalid Input");
		exit(0);
	}

	/*Remove newline from input*/
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
			printf("%s\n", *(environment + k));
			k++;
		}
	}

	return (input);
}
