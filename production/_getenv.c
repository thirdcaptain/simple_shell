#include "header.h"

/**
 * _getenv - searches the environment for given string
 * @name: name to search for in environment
 *
 * Return: string that contains name
*/
char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;
	char *str;

	while (*environ)
	{
		i = 0;
		j = 0;
		while (name[i] != '\0' && (*environ)[j] != '=')
		{
			if (name[i] == (*environ)[j])
			{
				i++;
				j++;
			}
			else
		{
				break;
		}
		}
		if ((*environ)[j] == '=' && name[i] == '\0')
			break;
		(*environ)++;
	}

	j++;
	str = malloc(sizeof(char) * 1024);
	if (str == NULL)
		return (NULL);
	while ((*environ)[j] != '\0')
	{
		str[k] = (*environ)[j];
		j++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
