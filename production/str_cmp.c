#include "header.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 *
 * Return: 0 if same word, integer if not
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
