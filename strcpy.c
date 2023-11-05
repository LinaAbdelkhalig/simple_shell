#include "main.h"

/**
 * _strcpy - copy the string pointed to by src to dest
 * @src: the string to be copied
 * @dest: pointer to the buffer where the src is copied
 * Return: pointer to teh copied string dest
 */

char *_strcpy(char *dest, char *src)
{
	size_t len = _strlen(src), i;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}
