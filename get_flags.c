#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @index: Index to check for flags
 * Return: Flags:
 */
int get_flags(const char *format, int *index)
{
	int flag_index, curr_index;
	int flags = 0;
	const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_index = *index + 1; format[curr_index] != '\0'; curr_index++)
	{
		for (flag_index = 0; FLAG_CHARS[flag_index] != '\0'; flag_index++)
		{
			if (format[curr_index] == FLAG_CHARS[flag_index])
			{
				flags |= FLAG_VALUES[flag_index];
				break;
			}
		}

		if (FLAG_CHARS[flag_index] == '\0')
			break;
	}

	*index = curr_index - 1;

	return (flags);
}
