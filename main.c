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
	int id, status;

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
			_env();

		args = _split(buff, " ");

		args[0] = search_path(args[0]);

		if (args[0] == NULL)
		{
			perror("Error");
			return (-1);
		}

		id = fork();
		if (id == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
		}
		free(args);
	}
	return (0);
}
