#include "main.h"

/**
 * printing_intigers - function that prints intigers
 * @args: arguments
 * Return: number of printed char
 */

int printing_intigers(va_list args)
{
	int r = va_arg(args, int);
	int lastdigit = r % 10;
	int exponent = 1;
	int s = 1;
	int number, digit; /*as helpers*/

	r = r / 10;
	number = r;

	if (lastdigit < 0)
	{
		_putchar('-');
		number = -number;
		r = -r;
		lastdigit = -lastdigit;
		s++;
	} /*to eliminate the negative*/

	if (number > 0)
	{
		while (number / 10 != 0)
		{
			exponent = exponent * 10;
			number = number / 10;
		}
		number = r;

		while (exponent > 0)
		{
			digit = number / exponent;
			_putchar(digit + '0');
			number = number - (digit * exponent);
			exponent = exponent / 10;
			s++;
		}
	}
	_putchar(lastdigit + '0');
	return (s);
}

#include "main.h"

/**
 * print_decimal - function that prints decimal
 * @args: argument
 * Return: number of char printed
 */

int print_decimal(va_list args)
{
	int r = va_arg(args, int);
	int lastdigit = r % 10;
	int exponent = 1;
	int s = 1;
	int number, digit;/*as helpers*/

	r = r / 10;
	number = r;

	if (lastdigit < 0)
	{
		_putchar('-');
		number = -number;
		r = -r;
		lastdigit = -lastdigit;
		s++;
	}

	if (number > 0)
	{
		while (number / 10 != 0)
		{
			exponent = exponent * 10;
			number = number / 10;
		}
		number = r;
		while (exponent > 0)
		{
			digit = number / exponent;
			_putchar(digit + '0');
			number = number - (digit * exponent);
			exponent = exponent / 10;
			s++;
		}
	}
	_putchar(lastdigit + '0');
	return (s);
}
