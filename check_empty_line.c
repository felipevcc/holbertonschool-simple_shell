#include "main.h"

/**
 * empty_line - checks if exists a empty line
 * @buff: line
 * Return: 0 or 1 (int)
 */

int empty_line(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] != ' ')
			return (0);
	}
	return (1);
}
