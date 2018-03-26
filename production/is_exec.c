#include "header.h"

/**
 * is_exec - checks if file exists
 * @path: takes in matrix of strings
 * @name: string to check access against
 *
 * Return: executable file, original string, or error
*/
char *is_exec(char **path, char *name)
{
	char *str;
	int ret_stat;

	while (*path)
	{
		str = append(*path, name);
		if (access(name, F_OK) != -1)
			return (name);
		if (access(str, F_OK) != -1)
			return (str);
		path++;
	}
	return ("File doesn't exist or it hit null");
}
