#include "holberton.h"
/**
 * count_spaces - count spaces from modulo to spec
 * @format: input format
 * @cnt: input format counter
 * Return: space size
 */
int count_spaces(const char *format, int cnt)
{
	int x;
	char *space;

	space = " ";
	for (x = 1; format[cnt + x] == space[0]; x++)
		;
	return (x - 1);
}
