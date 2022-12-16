#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer 1
 * @s2: pointer 2
 * Return: result
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}
	return (0);
}

/**
 * _strcpy - function that copies the string pointed to by src
 * @dest: pointer
 * @src: ponter
 * Return: @dest
 */
char *_strcpy(char *dest, char *src)
{
	char *c = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (c);
}

char **_split(char *str, char *sep)
{
	char *aux, **split_str;
	int i = 0;

	aux = strtok(str, sep);
	split_str = (char **)malloc(sizeof(char *) *100);

	while (aux != NULL)
	{
		split_str[i] = aux;
		/*printf("%s\n", split_str[i]);*/
		aux = strtok(NULL, sep);
		i++;
	}
	/*printf("%s\n", split_str[1]);*/
	return (split_str);
}
