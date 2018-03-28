#include "holberton.h"
/**
 * spec_len - get length of spec
 * @format: input format
 * @i: input format marker
 * Return: return count
 */
int spec_len(const char *format, int i)
{
	int cnt;
	char *space;

	space = " ";
	for (cnt = 1; format[i + cnt] != space[0]; cnt++)
		;
	return (cnt - 1);
}
