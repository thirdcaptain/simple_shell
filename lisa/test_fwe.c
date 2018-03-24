#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	int i, status, n;
	pid_t home;
	n = 5;

	char *argv[] = {"/bin/ls", "-l", "/bin", NULL};

	for (i = 0; i < n; i++)
	{
		printf("Before execve\n");
		home = fork();
		if (home < 0)
		{
			perror("Error");
			exit(1);
		}
		else if (home == 0)
		{
			printf("we made it");
			execve(argv[0], argv, NULL);
			printf("after execve");
		}
		wait(&status);
	}
	return (0);
}
