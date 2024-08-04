#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for testing _printf
 *
 * Return: Always 0
 */
int main(void)
{
	int len;

    /* Test character printing */
	len = _printf("Character: %c\n", 'A');
	printf("Returned length: %d\n", len);

    /* Test string printing */
	len = _printf("String: %s\n", "Hello, world!");
	printf("Returned length: %d\n", len);

    /* Test integer printing */
	len = _printf("Integer: %d\n", 12345);
	printf("Returned length: %d\n", len);

    /* Test signed integer printing */
	len = _printf("Signed integer: %i\n", -67890);
	printf("Returned length: %d\n", len);

    /* Test percentage sign */
	len = _printf("Percentage: %%\n");
	printf("Returned length: %d\n", len);

    /* Test null string */
	len = _printf("Null string: %s\n", NULL);
	printf("Returned length: %d\n", len);

    /* Test empty format string */
	len = _printf("");
	printf("Returned length: %d\n", len);

    /* Test format specifier not in _printf */
	len = _printf("Unknown specifier: %x\n");
	printf("Returned length: %d\n", len);

	return (0);
}
