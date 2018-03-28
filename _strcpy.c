#include "holberton.h"
/**
 * _strcpy - copies a string onto a diffrent array
 * @dest: where array is copied to
 *@src:array to copy
 * Return: dest array
 */

char *_strcpy(char *dest, char *src)
{
	int count;

	for (count = 0; src[count] != '\0'; count++)
		dest[count] = src[count];
	return (dest);
}
