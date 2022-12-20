#include "main.h"

/**
 * main - open shell, project base
 * Return: int
 */

int main(void)
{
	char *buff = NULL;
	char **args;
	size_t read_size = 0;
	ssize_t buff_size = 0;
	int id, i = 0;

	while (1)
	{
		if (isatty(0))
			printf("hsh$ ");

		buff_size = getline(&buff, &read_size, stdin);
		if (buff_size == -1)
			break;
		buff[buff_size - 1] = '\0';

		args = _split(buff, " ");

		if (_strcmp("exit", buff) == 0)
			break;

		args[0] = search_path(args[0]);

		id = fork();
		if (id == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("Error");
		}
		else
			wait(NULL);

		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	return (0);
}
