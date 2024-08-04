#include "main.h"

/**
 * print_hex - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int print_hex(va_list val)
{
	int index;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int tem = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (index = 0; index < counter; index++)
	{
		array[index] = tem % 16;
		tem /= 16;
	}
	for (index = counter - 1; index >= 0; index--)
	{
		if (array[index] > 9)
			array[index] = array[index] + 39;
		_putchar(array[index] + '0');
	}
	free(array);
	return (counter);
}
