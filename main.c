#include "main.h"

/**
 * frees - frees before exiting
 * @argv: argv
 * @cmd: cmd
 * @cmd_cp: cmd copy
 */

void frees(char ***argv, char **cmd, char **cmd_cp)
{
	int i;

	for (i = 0; (*argv)[i] != NULL; i++)
	{
		free((*argv)[i]);
		((*argv)[i]) = NULL;
	}

	free(*argv);
	*argv = NULL;
	free(*cmd);
	*cmd = NULL;
	free(*cmd_cp);
	*cmd_cp = NULL;
}

/**
 * main - the main function
 * @argc: the number of arguments passed to the function
 * @argv: the array of arguments passed to the function
 * Return: int
 */

int main(int argc, char **argv)
{
	char *prmpt = "($) ", *cmd = NULL, *cmd_cp = NULL, *tokenize;
	const char *delimit = " \n";
	ssize_t num_of_chars;
	size_t n = 0;
	int token_num = 0, i, interactiv = isatty(STDIN_FILENO);

	(void)argc;
	while (1)
	{
		if (interactiv)
			_puts(prmpt);
		num_of_chars = getline(&cmd, &n, stdin); /*get the input from user*/
		if (num_of_chars == 1 && cmd[0] == '\n') /*if the user enter*/
			continue;
		if (num_of_chars == -1) /*if the getline fails or ctr+d */
			exit(EXIT_SUCCESS);
		cmd_cp = _strdup(cmd);
		tokenize = strtok(cmd, delimit); /*start tokenizing the cmd*/
		while (tokenize)
		{
			token_num++;
			tokenize = strtok(NULL, delimit);
		}
		token_num++;
		argv = malloc(sizeof(char *) * token_num);
		tokenize = strtok(cmd_cp, delimit);
		if (tokenize == NULL)
		{
			frees(&argv, &cmd, &cmd_cp);
			continue;
		}
		for (i = 0; tokenize != NULL; i++)
		{
			argv[i] = _strdup(tokenize);
			tokenize = strtok(NULL, delimit);
		}
		argv[i] = NULL; /*terminate the string*/
		if (_strcmp(argv[0], "exit") == 0)
		{
			frees(&argv, &cmd, &cmd_cp);
			exit(EXIT_SUCCESS);
		}
		excmd(argv);
		frees(&argv, &cmd, &cmd_cp);
	}
	return (0);
}
