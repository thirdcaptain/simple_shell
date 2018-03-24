#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - creates a duplicate of a string
 * @str:string to be duplicated
 *
 * Return: Pointer to duplicate of string
 */

char *_strdup(char *str)
{
	int str_length = 0;
	char *dup_string;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		str_length++;
	}
	dup_string = malloc(str_length * (sizeof(char)) + 1);
	if (dup_string == NULL)
		return (NULL);
	for (i = 0; i < str_length; i++)
	{
		dup_string[i] = str[i];
	}
	return (dup_string);
}
