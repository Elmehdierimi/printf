#include "main.h"
/**
 * _strlen - Returns the length of a string.
 * @str: string pointer
 * Return: length of the string
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strlenc - Strlen fucntion but applied for constant char pointer str
 * @str: char pointer
 * Return: length of the string
 */
int _strlenc(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
