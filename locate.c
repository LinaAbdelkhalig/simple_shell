#include "main.h"
/**
 * free_paths - frees any path
 * @path: the path var
 * @path_cp: a copy of the path
 * @psychopath: the path of the command
 * Return: void
 */

void free_paths(char **path, char **path_cp, char **psychopath)
{
	if (*path)
	{
		free(*path);
		/**path = NULL;*/
	}
	if (*path_cp)
	{
		free(*path_cp);
		/**path_cp = NULL;*/
	}
	if (*psychopath)
	{
		free(*psychopath);
		/**psychopath = NULL;*/
	}
}

/**
 * _getenv - get the environment variable
 * @var_name: the name of the variable
 * Return: the vlaue of the variable if found
 */

char *_getenv(char *var_name)
{
	int i = 0;
	char **enviro = environ, *enviro_cp = NULL, *name, *value;

	while (enviro[i])
	{
		enviro_cp = _strdup(enviro[i]);
		if (!enviro_cp)
		{
			perror("Error");
			return (NULL);
		}
		name = _strtok(enviro_cp, "=");
		if (_strcmp(var_name, name) == 0)
		{
			value = _strdup((_strtok(NULL, "\0")));
			free(enviro_cp);
			return (value);
		}
		free(enviro_cp);
		i++;
	}
	return (NULL);
}

/**
 * create_psycho - creates the path of a file
 * @psychopath: the malloced string
 * @cmd: the command to be appended to the path
 * @dir: the directory where the file will be appended
 * Return: a pointer to the created string
 */

char *create_psycho(char *psychopath, char *cmd, char *dir)
{
	_strcpy(psychopath, dir);
	_strcat(psychopath, "/");
	_strcat(psychopath, cmd);
	_strcat(psychopath, "\0");

	return (psychopath);
}
/**
 * locate - locates the command passed to it in the PATH
 * @cmd: the command to be located
 * Return: the path of the command
 */

char *locate(char *cmd)
{
	char *path = _getenv("PATH"), *path_cp, *dir, *psychopath;
	int cmd_len;
	struct stat statbuf;

	if (path) /*if successful*/
	{
		path_cp = _strdup(path);
		if (!path_cp)
		{
			free(path);
			return (NULL);
		}
		cmd_len = _strlen(cmd);
		dir = _strtok(path_cp, ":");
		while (dir)
		{
			psychopath = malloc(_strlen(dir) + cmd_len + 2);
			if (!psychopath)
			{
				free(path), free(path_cp);
				return (NULL);
			}
			psychopath = create_psycho(psychopath, cmd, dir);
			if (stat(psychopath, &statbuf) == 0) /*if the cmd is in the ir*/
			{
				free(path), free(path_cp);
				return (psychopath); /*this path is correct*/
			}
			else
			{
				free(psychopath);
				psychopath = NULL;
				dir = _strtok(NULL, ":"); /*continue with the next dir in path*/
			}
		}
		free(path), free(path_cp);
		return (stat(cmd, &statbuf) == 0 ? _strdup(cmd) : NULL); /*cmdintheair */
	}
	free(path);
	return (NULL);
}
