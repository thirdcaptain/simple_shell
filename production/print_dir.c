#include "header.h"

/**
 * **print_dir - returns matrix of strings separated by colon
 * @str: string to be separated
 *
 * Return: matrix of strings
*/
char **print_dir(char *str)
{
	int i = 0;
	char **array;
	char *token;

	array = malloc(sizeof(char *) * 20);
	if (array == NULL)
		return (NULL);
	token = strtok(str, ":");
	while (token != NULL)
	{
		array[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	return (array);
}

