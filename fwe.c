\#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", ".", NULL};
	printf("Before execve\n");

	int i;
	int n = 5;
	int status = 0, status1  = 0;

/* Start children. */
	for (i = 0; i < n; ++i) {
	pid_t home = fork();
  		if (home < 0) {
    			perror("fork");
    			exit(1);
  		} else if (home == 0) {
    			/* execve on each child ? */
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
			}
			printf("After execve\n");
  		}
		else
			wait(&status);
	}
/* Wait for children to exit. */
	pid_t pid;
	pid_t ppid = getppid();
	while (n > 0) {
//  		pid = wait(&status1);
  		printf("Child's pid is :  %ld, exited with status: 0x%x\n", (long)pid, status);
  		printf("Parent's ppid is : %ld\n", (long)ppid);
		--n;
	}
	return (0);
}
