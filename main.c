#define _XOPEN_SOURCE_700
#define _GNU_SOURCE
#include "header.h"

/**
 * main - shell
 * @ac: argument count
 * @argv: arguments
 * @env: environmental parameters
 *
 * Return: 0 on success
 */

int main(int __attribute__((unused))ac, char **argv, char **env)
{
	char *path;
	char **path_dirs;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters = 0;
	char **args;
	char *filename;

	while (1)
	{
		path = _getenv("PATH", env);
		path_dirs = print_dir(path);
		buffer = NULL;
		args = NULL;
		bufsize = 0;
		characters = 0;
		write(STDIN_FILENO, "$ ", 2);
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == EOF)
		{
			free(path);
			free(buffer);
			if (isatty(STDIN_FILENO) == 1)
				write(STDERR_FILENO, "\n", 1);
			exit(0);
		}

		buffer = built_in(buffer, env);

		args = ret_array(buffer);

		filename = is_exec(path_dirs, buffer);
		fork_execute(filename, args, argv[0]);

		free(path_dirs);
		free(path);
		free(args);
		free(buffer);
	}
	return (0);
}
