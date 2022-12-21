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
	int id;

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
		else if (_strcmp("env", buff) == 0)
			_env();

		args[0] = search_path(args[0]);

		id = fork();
		if (id == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("Error");
		}
		else
			wait(NULL);
	}
	return (0);
}
