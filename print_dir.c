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
	int num_dirs = 0;

	num_dirs = 20;
	array = malloc(sizeof(char *) * num_dirs);
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
