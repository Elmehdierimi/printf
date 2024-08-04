#include "main.h"
/**
 * print_s - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int print_s(va_list val)
{
	char *str;
	int index, length;

	str = va_arg(val, char *);
	if (str == NULL)
	{
		str = "(null)";
		length = _strlen(str);
		for (index = 0; index < length; index++)
			_putchar(str[index]);
		return (length);
	}
	else
	{
		length = _strlen(str);
		for (index = 0; index < length; index++)
			_putchar(str[index]);
		return (length);
	}
}
