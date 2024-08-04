#include "main.h"

/**
 * print_hex_extra - prints an hexgecimal number.
 * @num: arguments.
 * Return: counter.
 */
int print_hex_extra(unsigned long int num)
{
	long int index;
	long int *array;
	long int counter = 0;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (index = 0; index < counter; index++)
	{
		array[index] = temp % 16;
		temp = temp / 16;
	}
	for (index = counter - 1; index >= 0; index--)
	{
		if (array[i] > 9)
			array[index] = array[index] + 39;
		_putchar(array[index] + '0');
	}
	free(array);
	return (counter);
}
