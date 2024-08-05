#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a character
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_char(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	char ch = va_arg(args, int);

	return (handle_write_char(ch, buf, flag_opts, w, prec, sz));
}

/************************* PRINT STRING *************************/

/**
 * print_string - Prints a string
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_string(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	int len = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buf);
	UNUSED(flag_opts);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);

	if (!str)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (prec >= 0 && prec < len)
		len = prec;

	if (w > len)
	{
		if (flag_opts & F_MINUS)
		{
			write(1, str, len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, str, len);
		}
		return (w);
	}

	return (write(1, str, len));
}

/************************* PRINT PERCENT SIGN *************************/

/**
 * print_percent - Prints a percent sign
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_percent(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	UNUSED(args);
	UNUSED(buf);
	UNUSED(flag_opts);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);

	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/

/**
 * print_int - Prints an integer
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_int(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	int index = BUFF_SIZE - 2;
	int neg_flag = 0;
	long int num = va_arg(args, long int);
	unsigned long int abs_num;

	num = convert_size_number(num, sz);

	if (num == 0)
		buf[index--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	abs_num = (unsigned long int)num;

	if (num < 0)
	{
		abs_num = (unsigned long int)((-1) * num);
		neg_flag = 1;
	}

	while (abs_num > 0)
	{
		buf[index--] = (abs_num % 10) + '0';
		abs_num /= 10;
	}

	index++;

	return (write_number(neg_flag, index, buf, flag_opts, w, prec, sz));
}

/************************* PRINT BINARY *************************/

/**
 * print_binary - Prints an unsigned number in binary
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	unsigned int number, mask, i, total;
	unsigned int binary_array[32];
	int bit_count;

	UNUSED(buf);
	UNUSED(flag_opts);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(sz);

	number = va_arg(args, unsigned int);
	mask = 2147483648; /* (2 ^ 31) */
	binary_array[0] = number / mask;
	for (i = 1; i < 32; i++)
	{
		mask /= 2;
		binary_array[i] = (number / mask) % 2;
	}
	for (i = 0, total = 0, bit_count = 0; i < 32; i++)
	{
		total += binary_array[i];
		if (total || i == 31)
		{
			char bit_char = '0' + binary_array[i];

			write(1, &bit_char, 1);
			bit_count++;
		}
	}

	return (bit_count);
}
