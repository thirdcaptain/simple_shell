#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * main - prints line using getline
 *
 * Return: 0 on success
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	size_t characters = 0;
	int status = 0;
	pid_t fork_ret = 0;
	char *args[50];
	int j = 0;

	while (1)
	{

		buffer = NULL;
		bufsize = 0;
	
		 if (buffer == NULL)
                        printf("it's null");
		while (*(buffer + j) != '\n')
               		j++;
		*(buffer + j) ='\0';
		
		if (buffer == NULL)
			printf("it's null");

		args[0] = buffer;
		args[1] = NULL;
		fork_ret = fork();
		if (fork_ret < 0)
		{
			perror("Fork failed\n");
			exit(1);
		}
		if (fork_ret == 0)
		{
			/* printf("Before execve\n"); */
			if (args[0] == NULL)
				printf("it's null");	
			else
				printf("%s\n", args[0]);
			printf("%s\n", args[0]);
			execve(args[0], args, NULL);
			printf("After execve :)\n"); 
		}
		else
		else
			wait(&status);
			if (buffer == NULL)
				printf("It's null");
			free(buffer);
		}
	}

	return (0);
}
