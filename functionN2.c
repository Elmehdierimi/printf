#include "main.h"

/**************** PRINT POINTER ****************/

/**
 * print_pointer - Prints the address of a pointer
 * @args: List of arguments
 * @buf: Buffer array for handling the print
 * @flag_opts: Active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_pointer(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	char padding_char = ' ';
	int index = BUFF_SIZE - 2;
	unsigned long address;
	const char hex_chars[] = "0123456789abcdef";
	void *ptr = va_arg(args, void *);

	UNUSED(w);
	UNUSED(sz);
	UNUSED(prec);

	if (!ptr)
		return (write(1, "(nil)", 5));

	buf[BUFF_SIZE - 1] = '\0';
	address = (unsigned long)ptr;

	while (address > 0)
	{
		buf[index--] = hex_chars[address % 16];
		address /= 16;
	}

	if (flag_opts & F_ZERO && !(flag_opts & F_MINUS))
		padding_char = '0';
	if (flag_opts & F_PLUS)
	{
		buf[index--] = '+';
	}
	else if (flag_opts & F_SPACE)
	{
		buf[index--] = ' ';
	}

	buf[index--] = 'x';
	buf[index--] = '0';

	index++;

	return (write_pointer(buf, index, BUFF_SIZE - index - 1,
		w, flag_opts, padding_char, ' ', 2));
}

/*********************** PRINT NON PRINTABLE ***********************/

/**
 * print_non_printable - Prints non-printable characters as hex values
 * @args: List of arguments
 * @buf: Buffer array for handling the print
 * @flag_opts: Active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_non_printable(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flag_opts);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);

	if (!str)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buf[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buf, i + offset);

		i++;
	}

	buf[i + offset] = '\0';

	return (write(1, buf, i + offset));
}

/*********************** PRINT REVERSE ***********************/

/**
 * print_reverse - Prints a string in reverse
 * @args: List of arguments
 * @buf: Buffer array for handling the print
 * @flag_opts: Active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_reverse(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	char *str;
	int length = 0;

	UNUSED(buf);
	UNUSED(flag_opts);
	UNUSED(w);
	UNUSED(sz);

	str = va_arg(args, char *);

	if (!str)
	{
		UNUSED(prec);
		str = ")Null(";
	}

	while (str[length])
		length++;

	while (length > 0)
	{
		write(1, &str[--length], 1);
	}

	return (length);
}

/*********************** PRINT A STRING IN ROT13 ***********************/

/**
 * print_rot13string - Prints a string encoded in ROT13
 * @args: List of arguments
 * @buf: Buffer array for handling the print
 * @flag_opts: Active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_rot13string(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	char output_char;
	char *str;
	unsigned int i, j;
	int count = 0;
	char input_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char  output_chars[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buf);
	UNUSED(flag_opts);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);

	if (!str)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; input_chars[j]; j++)
		{
			if (input_chars[j] == str[i])
			{
				output_char = output_chars[j];
				write(1, &output_char, 1);
				count++;
				break;
			}
		}
		if (!input_chars[j])
		{
			output_char = str[i];
			write(1, &output_char, 1);
			count++;
		}
	}
	return (count);
}
