#include "main.h"

/**
 * locate - locates the command passed to it in the PATH
 * @cmd: the command to be located
 * Return: the path of the command
 */

char *locate(char *cmd)
{
	char *path, *path_cp, *dir, *psychopath;
	int cmd_len, dir_len;
	struct stat statbuf;

	path = getenv("PATH"); /*get the PATH and store it in path*/

	if (path) /*if successful*/
	{
		path_cp = strdup(path); /*change to _strdup*/
		cmd_len = strlen(cmd); /*change to _strlen*/

		dir = strtok(path_cp, ":");
		while (dir)
		{
			dir_len = strlen(dir); /*change to _strlen*/
			psychopath = malloc(dir_len + cmd_len + 2);

			strcpy(psychopath, dir); /*change all these */
			strcat(psychopath, "/");
			strcat(psychopath, cmd);
			strcat(psychopath, "\0");
			if (stat(psychopath, &statbuf) == 0) /*if the cmd is in the ir*/
			{
				free(path_cp);
				return (psychopath); /*this path is correct*/
			}
			else
			{
				free(psychopath);
				dir = strtok(NULL, ":"); /*continue with the next dir in path*/
			}
		}
		free(path_cp);

		if (stat(cmd, &statbuf) == 0) /*if the command exits in the air*/
			return (strdup(cmd)); /*change to _stdup*/

		return (NULL);
	}
	return (NULL);
}
