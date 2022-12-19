#include "main.h"

/**
 * search_path - 
 * @command:
 * Return: 
 */

char *search_path(char *command)
{
	char *path = _getenv("PATH"), *path_cpy = NULL;
	char **path_split;
	char *path_concat = NULL;
	int i = 0, path_len = 0;
	struct stat info;

	path_cpy = _strcpy(path_cpy, path);
	path_split = _split(path_cpy, ":");

	while (path_split[i])
	{
		path_len = _strlen(path_split[i]);		

		if (path_split[i][path_len - 1] == '/')
			path_concat = _strcat(path_split[i], command);
		else
		{
			path_concat = _strcat(path_split[i], "/");
			path_concat = _strcat(path_concat, command);
		}

		if (stat(path_concat, &info) == 0)	
			break;

		printf("path[i] = %s\n", path_split[i]);	
		/*printf("path[i][len-1] = %c\n", path[i][path_len - 1]);*/

		/*path_concat = NULL;*/
		i++;
	}
	return (path_concat);
}
