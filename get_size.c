#include "main.h"

/**
 * get_size - Determines the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @index: Index to check for size specifiers
 *
 * Return: Size specifier.
 */
int get_size(const char *format, int *index)
{
	int current_index = *index + 1;
	int size_specifier = 0;

	if (format[current_index] == 'l')
		size_specifier = S_LONG;
	else if (format[current_index] == 'h')
		size_specifier = S_SHORT;

	if (size_specifier == 0)
		*index = current_index - 1;
	else
		*index = current_index;

	return (size_specifier);
}
