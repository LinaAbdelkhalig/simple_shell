#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @string: the string to be converted
 *
 * Return: the string as an integer
 */

int _atoi(char *string)
{
	unsigned int result = 0;
	int sign = 1;

	do {
		if (*string == '-')
			sign = sign * -1;
		else if (*string >= '0' && *string <= '9')
			result = (result * 10) + (*string - '0');
		else if (result > 0)
			break;
	} while (*string++);
	return (sign * result);
}
