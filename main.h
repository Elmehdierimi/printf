#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>



/**
 * struct format - converter for printf
 * @ph: type char pointer of the specifier
 * @function: function for the conversion specifier
 *
 */

typedef struct format
{
	char *ph;
	int (*function)(va_list);
} convert;

int print_decimal(va_list args);
int print_c(va_list val);
int print_37(void);
int print_s(va_list val);
int _putchar(char c);
int printing_intigers(va_list args);
int _strlen(char *str);
int _strlenc(const char *str);
int print_bin(va_list val);

#endif /* MAIN_H */
