#include "header.h"

/**
 * built_in - chops newline and executes exit and env built in functionality
 * @input: user input
 *
 * Return: string with newline removed
 */

char *built_in(char *input)
{
	int i = 0;

	if (input == NULL)
	{
		perror("Invalid Input");
		exit(0);
	}

	/*Remove newline from input*/
	while (*(input + i) != '\n')
		i++;
	*(input + i) = '\0';

	return (input);
}
