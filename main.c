#include "main.h"

/**
 * main - open shell, project base
 * Return: int
 */

int main(void)
{
	char *buff = NULL, **args;
	size_t read_size = 0;
	ssize_t buff_size = 0;
	int exit_status = 0;

	while (1)
	{
		if (isatty(0))
			printf("hsh$ ");

		buff_size = getline(&buff, &read_size, stdin);
		if (buff_size == -1 || _strcmp("exit\n", buff) == 0)
		{
			free(buff);
			break;
		}
		buff[buff_size - 1] = '\0';

		if (_strcmp("env", buff) == 0)
		{
			_env();
			continue;
		}

		if (empty_line(buff) == 1)
		{
			exit_status = 0;
			continue;
		}

		args = _split(buff, " ");
		args[0] = search_path(args[0]);

		if (args[0] != NULL)
			exit_status = execute(args);
		else
			perror("Error");
		free(args);
	}
	return (exit_status);
}
