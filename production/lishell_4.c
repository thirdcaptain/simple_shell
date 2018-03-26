#include "header.h"

/**
 * main - prints line using getline
 *
 * Return: 0 on success
 */
extern char **environ;

int main(int ac, char **argv)
{
	char *path;
	char **path_dirs;
	char *buffer = NULL;
        size_t bufsize = 0;
        size_t characters = 0;
        int status = 0;
        pid_t fork_ret = 0;
        char **args;
        int j = 0;
	char *filename;

	path = _getenv("PATH");
	path_dirs = print_dir(path);
        while (1)
        {
                buffer = NULL;
		args = NULL;
                bufsize = 0;
		characters = 0;
		status = 0;
		fork_ret = 0;
                j = 0;
                write(STDOUT_FILENO, "$ ", 2);
                characters = getline(&buffer, &bufsize, stdin);
                if (characters == EOF)
                {
                        free(buffer);
                        printf("\n");
                        exit(1);
                }
                if (buffer == NULL)
                        printf("it's null");
                while (*(buffer + j) != '\n')
                        j++;
                *(buffer + j) ='\0';

		if (_strcmp(buffer, "exit") == 0)
		{
			exit(1);
		}
		if (_strcmp(buffer, "env") == 0)
		{
			while (*environ)
			{
                		printf("%s\n", *environ);
                		*environ++;
        		}
		}
                args = ret_array(buffer);

		filename = is_exec(path_dirs, buffer);
		fork_ret = fork();
                if (fork_ret < 0)
                {       perror("Fork failed\n");
                        exit(1);
                }
                if (fork_ret == 0)
                {
			if (execve(filename, args, NULL) == -1)
				perror(argv[0]);
			exit(1);
                }
                else
                {
                        wait(&status);
                }
		filename = NULL;
		free(args);
		free(buffer);
        }
        return (0);
}
