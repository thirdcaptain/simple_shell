#include "header.h"

/**
 * token_count - count number of tokens
 * @str: string to tokenize
 *
 * Return: Number of tokens
 */


int token_count(char *str)
{
	int count = 0, i = 0;
	char *dup;

	dup = _strdup(str);
	if (dup[i] == '\0')
		return (1);
	while (dup[i] != '\0')
	{
		while (dup[i] == ' ')
		{
			i++;
		}
		if (dup[i] != '\0')
			count++;
		while (dup[i] != ' ' && dup[i] != '\0')
		{
			i++;
		}
	}
	free(dup);
	return (count);
}


/**
 * ret_array - for each word of a string received from getline
 * @string: breaks string into tokens
 *
 * Return: pointer to pointer of arrays of strings
 */

char **ret_array(char *string)
{
	int i = 0;
	int num_token = 0;
	char **array;
	char *token;

	num_token = token_count(string);
	array = malloc((sizeof(char *) * (num_token + 1)));
	if (array == NULL)
		return (NULL);
	token = strtok(string, " ");
	while (token != NULL)
	{
		array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	array[i] = NULL;
	return (array);
}
