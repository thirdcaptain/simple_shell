#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - prints line using getline
 *
 * Return: 0 on success
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	size_t characters;
	int status;
	int fork_ret;
	char *args[50];

	while (status != EOF)
	{
		write(STDOUT_FILENO, "$ ", 2);		
		characters = getline(&buffer, &bufsize, stdin);
		write(1, buffer, bufsize);
		args[0] = malloc(characters * sizeof(char));
		args[0] = buffer;	
		fork_ret = fork();
		if (fork_ret < 0)
		{	perror("Fork failed\n");
			exit(1);
		}
		if (fork_ret ==0)
		{
			 execve(args[0],args, NULL);
		}
		free(buffer);
		wait(&status);
	}
	return (0);
}
