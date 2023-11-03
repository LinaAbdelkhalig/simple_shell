#include "main.h"

/**
 * _strdup - returns a pointer to a new duplicated string of s
 * @string: the string in question
 * Return: on succes, a pointer to the duplicated string,
 * NULL if insufficient memory
 */

char *_strdup(char *string)
{
	size_t len = _strlen(string), i;
	char *dup = malloc(sizeof(char) * (len + 1));

	if (!dup)
	{
		perror("Error: ");
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		dup[i] = string[i];
	}
	dup[i] = '\0';

	return (dup);
}
