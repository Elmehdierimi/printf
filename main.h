#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int handle_format(char specifier, va_list args);
void _putchar(char c);

#endif /* MAIN_H */
