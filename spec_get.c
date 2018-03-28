#include "holberton.h"
/**
 * spec_get - get spec
 * @format: input format
 * @i: format cnt marker
 * Return: return spec
 */

char spec_get(const char *format, int i)
{
	int cnt = 0;
	char x;

	for (cnt = 0; format[i + cnt] != '\0'; cnt++)
	{
		if (format[i + cnt] <= 'z' && format[i + cnt] >= 'a')
		{
			x = format[i + cnt];
			break;
		}
		if (format[i + cnt] == 'R')
		{
			x = 'R';
			break;
		}
	}
	return (x);
}
