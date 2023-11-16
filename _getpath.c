#include "shell.h"
#include "stdio.h"
/**
 * _getpath - function that searches the path of the environment
 * @path: path of the variable
 * @command: input string
 * Return: path otherwise null
 */

char *_getpath(char *path, char *command)
{
	char **token, *fullpath, *pthcpy, *dir;
	int i = 1, length, dirsize;

	if (access(command, X_OK) == 0)
		return (command);
	length = strlen(command);
	pthcpy = malloc((sizeof(char) * strlen(path)) + 2);
	if (!pthcpy)
	{
		free(pthcpy);
		return (NULL);
	}
	strcpy(pthcpy, path);
	token = _strtok(pthcpy, ":");
	dir = token[1];
	while (dir)
	{
		dirsize = strlen(dir);
		fullpath = malloc(sizeof(char) * (length + dirsize + 2));
		if (!fullpath)
		{
			free(fullpath);
			return (NULL);
		}
		strcpy(fullpath, dir);
		fullpath[dirsize] = '/';
		strcpy(fullpath + dirsize + 1, command);
		fullpath[length + dirsize + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			dir = token[++i];
		}
		else
			break;
	}
	free(pthcpy);
	free(token);
	return (fullpath);
}
