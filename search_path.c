#include "main.h"

/**
 * search_path - 
 * @command:
 * Return: 
 */

char *search_path(char *command)
{
	char **path, **path2;
	char *path_concat = NULL;
	int i = 0, path_len = 0;
	struct stat info;

	path = _split(getenv("PATH"), ":");
	/*path2 = _split(getenv("PATH"), ":");*/

	while (path[i])
	{
		path_len = _strlen(path[i]);	

		/*printf("path2[i] = %s\n", path2[i]);*/

		if (path[i][path_len - 1] == '/')
			path_concat = _strcat(path[i], command);
		else
		{
			path_concat = _strcat(path[i], "/");
			path_concat = _strcat(path_concat, command);
		}

		if (stat(path_concat, &info) == 0)	
			break;

		/*path[i] = path2[i];*/
		printf("path[i] = %s\n", path[i]);	
		/*printf("path[i][len-1] = %c\n", path[i][path_len - 1]);*/

		/*path_concat = NULL;*/
		i++;
	}
	return (path_concat);
}
