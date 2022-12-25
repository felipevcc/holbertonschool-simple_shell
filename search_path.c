#include "main.h"

/**
 * search_path - search file between the path
 * @command: cmd
 * Return: cmd path
 */

char *search_path(char *command)
{
	char *path = _getenv("PATH"), *path_cpy, *ret;
	char **path_split;
	char *path_concat = NULL;
	int i = 0, path_len = 0;
	struct stat info;

	if (stat(command, &info) == 0)
		return (command);

	path_cpy = malloc(_strlen(path) + 1);

	path_cpy = _strcpy(path_cpy, path);
	path_split = _split(path_cpy, ":");

	while (path_split[i])
	{
		path_len = _strlen(path_split[i]);

		if (path_split[i][path_len - 1] != '/')
			path_concat = _strcat(path_split[i], "/");
		path_concat = _strcat(path_split[i], command);

		if (stat(path_concat, &info) == 0)
			break;

		i++;
	}
	ret = malloc(_strlen(path_concat) + 1);
	ret = _strcpy(ret, path_concat);
	free(path_cpy);

	if (!path_split[i])
	{
		free(ret);
		free(path_split);
		return (NULL);
	}

	free(path_split);
	return (ret);
}
