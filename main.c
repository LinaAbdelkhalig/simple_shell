#include "main.h"

/**
 * main - the main function
 * @argc: the number of arguments passed to the function
 * @argv: the array of arguments passed to the function
 * Return: int
 */

int main(int argc, char **argv)
{
	char *prmpt = "($)", *cmd = NULL, *cmd_cp = NULL, *tokenize;
	const char *delimit = " \n";
	ssize_t num_of_chars;
	size_t n = 0;
	int token_num = 0, i;

	(void)argc;
	while (1)
	{
		printf("%s ", prmpt); /*change to _puts*/
		num_of_chars = getline(&cmd, &n, stdin); /*get the input from user*/
		if (num_of_chars == 1 && cmd[0] == '\n') /*if the user enter*/
			continue;
		if (num_of_chars == -1) /*if the getline fails or ctr+d */
		{
			printf("Exiting shell...\n"); /*change to _puts*/
			return (-1);
		}
		cmd_cp = strdup(cmd); /*change to _strdup*/
		tokenize = strtok(cmd, delimit); /*start tokenizing the cmd*/
		while (tokenize)
		{
			token_num++;
			tokenize = strtok(NULL, delimit);
		}
		token_num++;
		argv = malloc(sizeof(char *) * token_num);
		tokenize = strtok(cmd_cp, delimit);
		for (i = 0; tokenize != NULL; i++)
		{
			argv[i] = strdup(tokenize); /*change to strdup*/
			tokenize = strtok(NULL, delimit);
		}
		argv[i] = NULL; /*terminate the string*/
		excmd(argv);
		for (i = 0; argv[i] != NULL; i++) /*free up the elemnts of argv*/
			free(argv[i]);
		free(argv), free(cmd), free(cmd_cp);
	}
	return (0);
}
