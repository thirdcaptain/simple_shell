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
	char *argv[];

	while (status != EOF)
	{
		write(STDOUT_FILENO, "$ ", 2);		
		characters = getline(&buffer, &bufsize, stdin);
		write(1, buffer, bufsize);
		argv[0] = malloc(characters * sizeof(char));
		argv[0] = buffer;	
		fork_ret = fork();
		execve(argv[0],argv, NULL);
		free(argv[0]);
		free(buffer);
		wait(&status);
	}
	return (0);
}
