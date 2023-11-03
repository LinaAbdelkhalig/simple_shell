#include "main.h"
/**
 * _putchar - writes the character to stdout
 * @c: the character to be written
 * Return: 1 if succeeded
 */

int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes the string to stdout
 * @string: the string to be written
 * Return: the number of written characters
 */

int _puts(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);

	return (i);
}
