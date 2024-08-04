#include "main.h"

/**
 * print_bin - prints binary number.
 * @val: parameter.
 * Return: integer
 */
int print_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (index = 0; i < 32; i++)
	{
		p = ((1 << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			_putchar((p >> (31 - i)) + '0');
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}
