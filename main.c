#include "main.h"

/**
 * main - open shell, project base
 * Return: int
*/

int main(void)
{
	char *buff = NULL;
	size_t buff_size = 0;
	/*char sep[] = " ";*/
	/*int i = 0;*/

	while (1)
	{
		if (isatty(0))
			printf("hsh$ ");
		buff_size = getline(&buff, &buff_size, stdin);
		if (buff_size == -1)
			break;

		buff[buff_size - 1] = '\0';
		if (execve(buff, NULL, NULL) == -1)
			perror("Error:");

		if (_strcmp("exit", buff) == 0)
			break;
		printf("\n");
	}
	return (0);
}
