#include "main.h"

/**
 * _strcat - appends the src string to the dest string
 * @dest: the string to be appended
 * @src: the string to be added to dest
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	size_t len = _strlen(dest), i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len] = src[i];
		len++;
	}
	dest[len] = '\0';

	return (dest);
}
