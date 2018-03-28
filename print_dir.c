#include "header.h"

/**
 * dir_count - count number of dirs
 * @str: string to convert into separate dirs
 *
 * Return: Number of dirs
 */

int dir_count(char *str)
{
	int count = 0;
	char *token;
	char *duplicate;

	duplicate = _strdup(str);

	token = strtok(duplicate, ":");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, ":");
	}
	free(duplicate);
	return (count);
}

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

	num_dirs = dir_count(str);
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
