#include "main.h"

/**
 * _getline - gets the input from the user
 * @cmd: the address of the bufer containing the text
 * @n: the length of the command
 * @file: the stream from which the command will be read
 * Return: the number of chars read
 */

ssize_t _getline(char **cmd, size_t *n, FILE *file)
{
	char *buffer;
	ssize_t rsize = 0;
	char *ptr; /*points to the buffer now*/
	size_t i = 0;

	if (!cmd || !n || !file)
		return (-1);
	if (!(*cmd) || !(*n))/*if cmd is empty allocate memory*/
	{
		*n = 1024;/*assign the size to the buffer size*/
		*cmd = malloc(*n);
		if (!(*cmd)) /*failed to malloc*/
			return (-1);
	}
	buffer = malloc(*n);
	if (!buffer)
		return (-1);
	while (1)
	{
		if (i >= *n)/*if the buffer is smaller than n*/
		{
			*n += 1024;
			*cmd = realloc(*cmd, *n);
			if (!(*cmd))/*failed to realloc*/
			{
				free(buffer);
				return (-1);
			}
		}
		if (rsize <= 0)/*if empty buffer read from file*/
		{
			rsize = read(fileno(file), buffer, *n);
			ptr = buffer;
		}
		if (rsize == 0) /*if inputing end*/
		{
			(*cmd)[i] = '\0';
			free(buffer);
			return (i > 0 ? (int)i : -1);/*if any chars read, return, else -1*/
		}
		else if (rsize < 0)/*if read failed*/
		{
			free(buffer);
			return (-1);
		}
		(*cmd)[i++] = *ptr++;/*assign the next char in buffer to cmd*/
		rsize--;
		if ((*cmd)[i - 1] == '\n')/*if new line entered*/
		{
			(*cmd)[i] = '\0';
			free(buffer);
			return (i);
		}
	}
}
