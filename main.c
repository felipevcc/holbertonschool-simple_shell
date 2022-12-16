#include "main.h"

/**
 * main - open shell, project base
 * Return: int
 */

int main(void)
{
	char *buff = NULL, *args[100], **tmp;
	size_t read_size = 0;
	ssize_t buff_size = 0;
	int id;
	/*int i;*/

	while (1)
	{
		if (isatty(0))
			printf("hsh$ ");

		buff_size = getline(&buff, &read_size, stdin);
		if (buff_size == -1)
			break;

		buff[buff_size - 1] = '\0';

		args[0] = buff;
		args[1] = NULL;

		if (_strcmp("exit", buff) == 0)
			break;

		tmp = _split(getenv("PATH"), ":");
		printf("%s\n", tmp[1]);
		
		id = fork();
		if (id == 0)
		{
			if (execve(buff, args, NULL) == -1)
				perror("Error:");
		}
		else
			wait(NULL);
	}

	free(args[0]);
	free(args[1]);
	return (0);
}
