#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list arg_list;
	int index = 0;

	va_start(arg_list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	while (format && format[index])
	{
		if (format[index] == '%' && format[index + 1])
		{
			index++;
			char_count += handle_format(format[index], arg_list);
		}
		else
		{
			_putchar(format[index]);
			char_count++;
		}
		index++;
	}
	va_end(arg_list);

	return (char_count);
}
