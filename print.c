#include "main.h"

/**
 * printf_c - prints a char
 * @val: arguments list containing the char to print.
 * Return: 1.
 */
int print_c(va_list val)
{
	char str;

	str = va_arg(val, int);
	_putchar(str);
	return (1);
}
