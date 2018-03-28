#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * _printf - custom printf
 * @format: input format
 * Return: total length of string printed
 */
int _printf(const char *format, ...)
{
	int cnt = 0, total = 0, spaces = 0, total1 = 0;
	char z;
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);
	while (format[cnt] != '\0')
	{
		if (format[cnt] == '%' && format[cnt + 1] == '\0')
			return (-1);
		else if (format[cnt] == '%' && format[cnt + 1] == '%')
		{
			_putchar(format[cnt + 1]);
			total += 1;
			cnt += 2;
		}
		else if (format[cnt] == '%')
		{
			z = spec_get(format, cnt);
			total1 = prog_get(z, list, format, cnt);
			total = total1 + total;
			spaces = count_spaces(format, cnt);
			cnt += (spaces + 2);
		}
		else
		{
			_putchar(format[cnt]);
			cnt++;
			total++;
		}

	}
	va_end(list);
	return (total);
}
