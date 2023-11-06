#include "main.h"

/**
 * excmd - executes the command passed to it
 * @argv: the string containing the command and args
 * @child_status: pointer to an in to store the child's exit status
 */

void excmd(char **argv, int *child_status)
{
	char *cmd = NULL, *og_cmd = NULL;
	pid_t pid;
	int status;

	if (argv)
	{
		cmd = argv[0]; /*the command will be the first string in the array*/
		og_cmd = locate(cmd); /*locate the path of the actual command*/

		if (!og_cmd)
		{
			perror("Error");
			return;
		}
		pid = fork();
		if (pid == -1) /*if the forking failed*/
		{
			free(og_cmd);
			perror("Error");
			return;
		}
		if (pid == 0) /*if we're in the child process*/
		{
			if (execve(og_cmd, argv, NULL) == -1) /*if the execution failed */
				perror("Error");
			free(og_cmd);
			exit(EXIT_FAILURE);
		}
		else /*we're in the parent process*/
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			*child_status = WEXITSTATUS(status);
			free(og_cmd);
		}
	}
}
