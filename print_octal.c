#include "main.h"

/**
 * print_oct - prints an octal number.
 * @val: arguments.
 * Return: counter.
 */
int print_oct(va_list val)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int tem = num;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		num /= 8;
		count++;
	}

	array = malloc(count * sizeof(int));
	if (!array)
		return (0);

	num = temp;
	for (i = 0;
			 i < count; i++)
	{
		array[i] = num % 8;
		num /= 8;
	}

	for (i = count - 1; i >= 0; i--)
		_putchar(array[i] + '0');
	free(array);
	return (count);
}
