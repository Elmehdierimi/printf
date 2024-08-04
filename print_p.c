#include "main.h"

/**
 * print_pointer - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int print_pointer(va_list val)
{
	void *ptr;
	char *s = "(nil)";
	long int x;
	int y;
	int i;

	ptr = va_arg(val, void*);
	if (ptr == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	x = (unsigned long int)ptr;
	_putchar('0');
	_putchar('x');
	y = print_hex_extra(x);
	return (y + 2);
}
