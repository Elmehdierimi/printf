#include "main.h"

/**
 * get_width - Determines the width for printing
 * @format: The formatted string with width specifier
 * @pos: Current index in the format string
 * @args: Variable argument list
 *
 * Return: Calculated width as an integer.
 */
int get_width(const char *format, int *pos, va_list args)
{
	int index = *pos + 1;
	int width = 0;

	while (format[index] != '\0')
	{
		if (is_digit(format[index]))
		{
			width = width * 10 + (format[index] - '0');
		}
		else if (format[index] == '*')
		{
			index++;
			width = va_arg(args, int);
			break;
		}
		else
		{
			break;
		}
		index++;
	}
	*pos = index - 1;

	return (width);
}
