#include "holberton.h"
/**
 * print_string - return string
 * @list: input va_list
 * Return: return string
 */

int print_string(va_list *list)
{
	char *c;
	int cnt = 0;

	c = va_arg(list, char *);
	if (c == NULL)
	{
		c = "(null)";
	}
	for (cnt = 0; c[cnt] != '\0'; cnt++)
		_putchar(c[cnt]);
	return (cnt);
}
