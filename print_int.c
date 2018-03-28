#include "holberton.h"
/**
 * print_int - prints int
 * @list: inputs va_list
 * Return: returns a str and null
 */

int print_int(va_list list)
{
	int a, b, res, tmp, exp, cnt;

	a = va_arg(list, int);
	cnt = b = 0;
	exp = 1;
	if (a >= 0)
		(res = a * -1);
	else
		(res = a, cnt++);
	tmp = res;
	while (tmp <= -10)
	{
		exp *= 10;
		tmp /= 10;
		cnt++;
	}
	if (a < 0)
		_putchar('-');
	while (exp >= 1)
	{
		_putchar((((res / exp) % 10) * -1 + '0'));
		exp /= 10;
	}
	return (cnt + 1);
}
