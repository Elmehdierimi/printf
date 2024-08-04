#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_format - handles different format specifiers
 * @specifier: format specifier character
 * @args: va_list variable
 *
 * Return: number of characters printed
 */
int handle_format(char specifier, va_list args)
{
	int count = 0;
	char buffer[32];
	int i;

	switch (specifier)
	{
		case 'c':
			_putchar(va_arg(args, int));
			count++;
			break;
		case 's':
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				for (i = 0; str[i]; i++)
				{
					_putchar(str[i]);
					count++;
				}
				break;
			}
		case 'd':
		case 'i':
			{
				int num = va_arg(args, int);

				sprintf(buffer, "%d", num);
				for (i = 0; buffer[i]; i++)
				{
					_putchar(buffer[i]);
					count++;
				}
				break;
			}
		case '%':
			_putchar('%');
			count++;
			break;

		default:
			_putchar('%');
			_putchar(specifier);
			count += 2;
			break;
	}

	return (count);
}
