#include "main.h"

/**
 * main -
*/
int main(void)
{
	char *buff = NULL;
	size_t buff_size;
	char sep[] = " ";
	char *buff_args = NULL;
	int i = 0;

	while (1)
	{
		printf("hsh$ ");	
		getline(&buff, &buff_size, stdin);


		while (buff_args[i])
		{
			if (i == 0)
				buff_args[i] = strtok(buff, sep);
			else
				buff_args[i] = strtok(NULL, sep);
			i++;
		}

		

		printf("%s\n", buff_args);
		break;
	}
	return (0);	
}
