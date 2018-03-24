#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

extern char **environ;

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

char **print_dir(char *str)
{
        int i = 0;
        char **array;
        char *token;

        array = malloc(sizeof(char *) * 20);
	if (array == NULL)
		return NULL;
        token = strtok(str, ":");
        while (token != NULL)
        {
                array[i] = token;
		i++;
                token = strtok(NULL, ":");
	}
/*      array[i + 1] = NULL; */
        return (array);
}

char *append(char *path, char *name)
{
        int namelen = 0, pathlen = 0, i = 0, j = 0, k = 0, lengths = 0;
        char *tmp;

        while (name[namelen] != '\0')
                namelen++;

                i = 0;
                j = 0;
                pathlen = 0;

                while (path[pathlen] != '\0')
                {
                        pathlen++;
                }
                lengths = pathlen + namelen;

                tmp = malloc(sizeof(char) * lengths + 2);
                if (tmp == NULL)
                        return (NULL);

                for(i = 0; i < pathlen; i++)
                {
                        tmp[i] = path[i];
                }
                tmp[i] = '/';
                i++;
                while (name[k] != '\0')
                {
                        tmp[i] = name[k];
                        k++;
                        i++;
                }
                tmp[i + 1] = '\0';

        return (tmp);
}

char *is_exec(char **path, char *name)
{
        char *str;
        int ret_stat;

        while (*path)
        {
                str = append(*path, name);
                if (access(str, F_OK) != -1)
                        return (str);
                else
                        path++;
        }
        return ("File doesn't exist or it hit null");
}

/**
 * main - prints line using getline
 *
 * Return: 0 on success
 */

int main(int ac, char **argv)
{
	char *path;
	char **path_dirs;
	char *buffer = NULL;
        size_t bufsize = 0;
        size_t characters = 0;
        int status = 0;
        pid_t fork_ret = 0;
        char *args[50];
        int j = 0;
        char *program;
	char *filename;

        program = argv[0];
	path = _getenv("PATH");
	path_dirs = print_dir(path);
        while (1)
        {
                buffer = NULL;
                bufsize = 0;
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

                if (buffer == NULL)
                        printf("it's null");

                args[0] = buffer;
		args[1] = NULL;
		filename = is_exec(path_dirs, buffer);
		fork_ret = fork();
                if (fork_ret < 0)
                {       perror("Fork failed\n");
                        exit(1);
                }
                if (fork_ret == 0)
                {
                      execve(filename, args, NULL);
                      perror(argv[0]);
                      _exit(1);
                      exit(1);
                }
                else
                {
                        wait(&status);
                        free(buffer);
                }
        }
        return (0);
}
