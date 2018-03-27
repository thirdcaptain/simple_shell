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
	int diff;
	int c = 0;

	while ((s1[c] != '\0' || s2[c] != '\0') && (s1[c] == s2[c]))
	{
		c++;
	}
	if (s1[c] != s2[c])
	{
		diff = s1[c] - s2[c];
	}
	else
	{
		diff = 0;
	}
	return (diff);
}
