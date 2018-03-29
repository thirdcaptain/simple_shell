#include "header.h"

/**
 * _strlen - finds length of string
 * @str: string to count
 * Return: length of string
*/
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
