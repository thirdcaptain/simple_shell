#include "holberton.h"
/**
 * _strlen - displays string length
 * @s: inputs string
 * Return: length size
 */

int _strlen(char *s)
{
	int count, length = 0;


	for (count = 0; *(s + count) != '\0'; count++)
	{
		length++;
	}

	return (length);
}
