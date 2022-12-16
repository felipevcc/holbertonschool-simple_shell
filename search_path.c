#include "main.h"

/**
 * search_path - 
 * @command:
 * Return: 
 */

char *search_path(char *command)
{
    char *path = getenv("PATH"), *aux = NULL, *split_path[100], *cpy_path = NULL;
	int i = 0;
	(void)command;

    _strcpy(cpy_path, path);

    while ((aux = strtok(path, ":")) != NULL)
    {
        /*printf("%s\n", aux);*/
		split_path[i] = aux;
		printf("%s\n", split_path[i]);
		aux = NULL;
		i++;
    }
	return (*split_path);
}