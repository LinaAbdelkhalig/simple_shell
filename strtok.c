#include "main.h"

/**
 * _strtok - breaks a string to a sequence of tokens
 * @string: the string to be tokenized
 * @delimit: string containing the delimiters to the tokens
 * Return: null-terminated string containing the next token
 *	excluding the delimiting byte or NULL
 */

char *_strtok(char *string, const char *delimit)
{
	static char *next_token;
	char *token;
	int j;

	if (string != NULL)/*first call, start ur token from the new string passed*/
		next_token = string;
	if (next_token == NULL)/*if there are no tokens return null*/
		return (NULL);
	for (; *next_token != '\0'; next_token++)/*skip leading spaces*/
	{
		for (j = 0; delimit[j] != '\0'; j++)
		{
			if (*next_token == delimit[j])
				break;
		}
		if (delimit[j] == '\0')
			break;
	}
	if (*next_token == '\0')/*if the string is all spaces return null*/
	{
		next_token = NULL;
		return (NULL);
	}

	token = next_token; /*new token begins*/
	for (; *next_token != '\0'; next_token++)/*loop through looking for delimits*/
	{
		for (j = 0; delimit[j] != '\0'; j++)
		{
			if (*next_token == delimit[j])
			{
				*next_token = '\0';/*replace the delimit with \0*/
				next_token++;
				return (token);
			}
		}
	}
	next_token = NULL;/*end of string and no delimits*/

	return (token);
}
