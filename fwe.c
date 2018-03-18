#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	printf("Before execve\n");

	pid_t pids[10];
	int i;
	int n = 5;

/* Start children. */
	for (i = 0; i < n; ++i) {
  		if ((pids[i] = fork()) < 0) {
    			perror("fork");
    			exit(1);
  		} else if (pids[i] == 0) {
    			/* execve on each child ? */
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
			}
			printf("After execve\n");
    			return (0);
  		}
	}

/* Wait for children to exit. */
	int status;
	pid_t pid;
	pid_t ppid = getppid();
	while (n > 0) {
  		pid = wait(&status);
  		printf("Child's pid is :  %ld, exited with status: 0x%x\n", (long)pid, status);
  		printf("Parent's ppid is : %ld\n", (long)ppid);
		--n;
	}
}
