#include "holberton.h"
/**
 * prog_get - get program
 * @c: input specifier
 * @list: input va_list
 * @format: input format
 * @cnt: format counter
 * Return: function pointer or null
 */

int prog_get(char c, va_list list, const char *format, int cnt)
{
	print_list prog_list[] = {
		{"s", print_string},
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{'\0', NULL}
	};
	int i = 0;

	while (prog_list[i].spec)
	{
		if (c == *prog_list[i].spec)
		{
			return (prog_list[i].p(list));
		}
		i++;
	}
	if (prog_list[i].spec == '\0')
	{
		_putchar(format[cnt]);
		_putchar(format[cnt + 1]);
		return (2);
	}
	return (0);
}
