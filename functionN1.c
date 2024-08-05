#include "main.h"

/********************** PRINT UNSIGNED NUMBER **********************/

/**
 * print_unsigned - Prints an unsigned integer
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);

	number = convert_size_unsgnd(number, sz);

	if (number == 0)
		buf[index--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buf[index--] = (number % 10) + '0';
		number /= 10;
	}

	index++;

	return (write_unsgnd(0, index, buf, flag_opts, w, prec, sz));
}

/********** PRINT UNSIGNED NUMBER IN OCTAL  *************/
/**
 * print_octal - Prints an unsigned integer in octal notation
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int original_number = number;

	UNUSED(w);

	number = convert_size_unsgnd(number, sz);

	if (number == 0)
		buf[index--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buf[index--] = (number % 8) + '0';
		number /= 8;
	}

	if (flag_opts & F_HASH && original_number != 0)
		buf[index--] = '0';

	index++;

	return (write_unsgnd(0, index, buf, flag_opts, w, prec, sz));
}

/*********** PRINT UNSIGNED NUMBER IN HEXADECIMAL ***********/
/**
 * print_hexadecimal - Prints an unsigned integer in hexadecimal notation
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	return (print_hexa(args, "0123456789abcdef", buf,
		flag_opts, 'x', w, prec, sz));
}

/********** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***********/
/**
 * print_hexa_upper - Prints an unsigned integer in upper hexadecimal notation
 * @args: List of arguments
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list args, char buf[],
	int flag_opts, int w, int prec, int sz)
{
	return (print_hexa(args, "0123456789ABCDEF", buf,
		flag_opts, 'X', w, prec, sz));
}

/*********** PRINT HEXADECIMAL NUM IN LOWER OR UPPER ***********/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper case
 * @args: List of arguments
 * @map_digits: Array of characters for mapping the number
 * @buf: Buffer array to handle printing
 * @flag_opts: Calculates active flags
 * @flag_char: Character for flagging
 * @w: Width specifier
 * @prec: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of characters printed
 */
int print_hexa(va_list args, char map_digits[], char buf[],
	int flag_opts, char flag_char, int w, int prec, int sz)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int original_number = number;

	UNUSED(w);

	number = convert_size_unsgnd(number, sz);

	if (number == 0)
		buf[index--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buf[index--] = map_digits[number % 16];
		number /= 16;
	}

	if (flag_opts & F_HASH && original_number != 0)
	{
		buf[index--] = flag_char;
		buf[index--] = '0';
	}

	index++;

	return (write_unsgnd(0, index, buf, flag_opts, w, prec, sz));
}
