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
	int i = 0, k = 0, j = 0, a = 0;
	size_t length = 0;
	char *newstr;

	if (input == NULL)
	{
		perror("Invalid Input");
		exit(0);
	}
	while (*(input + i) != '\n')
		i++;
	*(input + i) = '\0';

	while (*(input + j) == ' ')
		j++;
	i -= j;
	newstr = malloc(sizeof(char) * i);
	while(*(input + j) != '\0')
	{
		newstr[a] = (input[j]);
		a++;
		j++;
	}
	

	if (_strcmp(newstr, "exit") == 0 && newstr[0] != '\0')
	{
		exit(0);
	}
	if (_strcmp(newstr, "env") == 0 && newstr[0] != '\0')
	{
		while (*(environment + k) != NULL)
		{	
			length = _strlen(*(environment + k));
			write(STDOUT_FILENO, *(environment + k), length);
			write(STDOUT_FILENO, "\n", 1);
			k++;
		}
	}

	return (newstr);
}
