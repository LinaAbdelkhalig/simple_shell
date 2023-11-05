#include "main.h"

/**
 * _env - prints a list of environment variables
 * @environ: the environment
 */

void _env(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
}
