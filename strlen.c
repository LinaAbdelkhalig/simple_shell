#include "main.h"

/**
 * _strlen - gets the length of a string
 * @string: the string in question
 * Return: the string length
 */

size_t _strlen(char *string)
{
	size_t length;

	for (length = 0; string[length] != '\0'; length++)
		;

	return (length);
}
