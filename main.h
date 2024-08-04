#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...)
int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list val);
int printf_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_37(void);
int printing_intigers(va_list args);
int print_decimal(va_list args);

#endif
