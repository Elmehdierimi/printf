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

int print_d(va_list args);
int print_c(va_list val);
int print_37(void);
int print_s(va_list val);
int _putchar(char c);
int print_i(va_list args);
int _strlen(char *str);
int _strlenc(const char *str);
int print_bin(va_list val);
int print_oct(va_list val);
int print_pointer(va_list val);
int print_hex_extra(unsigned long int num);
int print_hex(va_list val);
int _printf(const char *format, ...);
#endif /* MAIN_H */
