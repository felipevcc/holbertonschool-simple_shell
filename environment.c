#include "main.h"

/**
 * _getenv - get env variables
 * @env_var: env variable
 * Return: env variable result, its content
 */

char *_getenv(char *env_var)
{
	int i = 0, j;
	int status;

	while (environ[i])
	{
		status = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env_var[j])
				status = 0;
		}
		if (status == 1)
			break;
		i++;
	}
	return (&environ[i][j + 1]);
}
