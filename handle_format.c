#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_char - prints a character.
 * @args: va_list variable.
 * Return: number of characters printed.
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - prints a string.
 * @args: va_list variable.
 * Return: number of characters printed.
 */
int print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}

	return (count);
}

/**
 * print_int - prints an integer.
 * @args: va_list variable.
 * Return: number of characters printed.
 */
int print_int(va_list args)
{
	char buffer[32];
	int count = 0;
	int num = va_arg(args, int);

	sprintf(buffer, "%d", num);
	for (int i = 0; buffer[i]; i++)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}

/**
 * handle_format - handles different format specifiers.
 * @specifier: format specifier character.
 * @args: va_list variable.
 * Return: number of characters printed.
 */
int handle_format(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count = print_char(args);
			break;
		case 's':
			count = print_string(args);
			break;
		case 'd':
		case 'i':
			count = print_int(args);
			break;
		case '%':
			_putchar('%');
			count = 1;
			break;
		default:
			_putchar('%');
			_putchar(specifier);
			count = 2;
			break;
	}

	return (count);
}
