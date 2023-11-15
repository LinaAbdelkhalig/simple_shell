#include "main.h"

/**
 * frees - frees before exiting
 * @argv: argv
 * @cmd: cmd
 */

void frees(char ***argv, char **cmd)
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
}

/**
 * get_cmd - gets the command from user input
 * @cmd: pointer to the command string
 * @n: size of the command string
 * @child_status: pointer to the exiting status
 * Return: number of characters in the command
 */
ssize_t get_cmd(char **cmd, size_t *n, int *child_status)
{
	ssize_t num_of_chars, i = 0;

	num_of_chars = getline(cmd, n, stdin);
	if (num_of_chars == -1)
	{
		free(*cmd);
		*cmd = NULL;
		exit(*child_status);
	}

	if ((*cmd)[0] == '#')
	{
		free(*cmd);
		*cmd = NULL;
		return (0);
	}
	for (i = 0; (*cmd)[i] != '\0'; i++)
	{
		if ((*cmd)[i] == '#' && (*cmd)[i - 1] == ' ')
		{
			(*cmd)[i] = '\0';
			break;
		}
	}
	return (_strlen(*cmd));
}

/**
 * tokenize_cmd - tokenize the command to an array of strings
 * @cmd: pointer to the command string to tokenize
 * @argv: pointer to the array of strings
 * Return: number of tokens in the command
 */

int tokenize_cmd(char **cmd, char ***argv)
{
	char *cmd_cp = NULL, *tokenize;
	const char *delimit = " \n";
	int token_num = 0, i;

	cmd_cp = _strdup(*cmd);
	tokenize = _strtok(*cmd, delimit);
	while (tokenize)
	{
		token_num++;
		tokenize = _strtok(NULL, delimit);
	}
	token_num++;
	*argv = malloc(sizeof(char *) * token_num);
	if (!*argv)
	{
		free(*cmd);
		*cmd = NULL;
		free(cmd_cp);
		exit(EXIT_FAILURE);
	}
	tokenize = _strtok(cmd_cp, delimit);
	if (tokenize == NULL)
	{
		free(*argv);
		*argv = NULL;
		free(*cmd);
		*cmd = NULL;
		free(cmd_cp);
		return (-1);
	}
	for (i = 0; tokenize; i++)
	{
		(*argv)[i] = _strdup(tokenize);
		tokenize = _strtok(NULL, delimit);
	}
	(*argv)[i] = NULL;
	free(cmd_cp);
	return (i);
}

/**
 * main - the main function
 * @argc: the number of arguments passed to the function
 * @argv: the array of arguments passed to the function
 * @environ: the environment
 * Return: int
 */

int main(int argc, char **argv, char **environ)
{
	char *prmpt = "($) ", *cmd = NULL;
	ssize_t num_of_chars;
	size_t n = 0;
	int i, interactiv = isatty(STDIN_FILENO), child_status = 0;

	(void)argc;
	while (1)
	{
		if (interactiv)
			_puts(prmpt);
		num_of_chars = get_cmd(&cmd, &n, &child_status); /*get the input from user*/
		/*if the user enter or comment only*/
		if ((num_of_chars == 1 && cmd[0] == '\n') || (num_of_chars == 0))
			continue;
		i = tokenize_cmd(&cmd, &argv);/*tokenize and return no. of tokens*/
		if (i == -1)
			continue;
		if (_strcmp(argv[0], "exit") == 0)
		{
			if (argv[1])
			{
				child_status = _atoi(argv[1]);
				if (child_status < 0 || (child_status == 0 && _strcmp(argv[1], "0") != 0))
				{
					write(2, "./hsh: 1: exit: Illegal number: ", 32);
					write(2, argv[1], _strlen(argv[1])), write(2, "\n", 1);
					child_status = 2;
				}
			}
			frees(&argv, &cmd);
			exit(child_status);
		}
		if (_strcmp(argv[0], "env") == 0)
			_env(environ);
		else
			excmd(argv, &child_status);
		frees(&argv, &cmd);
	}
	return (0);
}
