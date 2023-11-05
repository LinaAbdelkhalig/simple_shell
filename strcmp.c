#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 * Description: compares two strings s1 & s2.
 * The comparison is done using unsigned characters
 * Return: an integer indicating the result of comparison:
 *	-  0, if the s1 and s2 are equal
 *	- negative if s1 is less than s2
 *	- positive if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
