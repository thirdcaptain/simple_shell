#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status;

    status = 1;
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("Wait for me, wait for me\n");
	printf("%d\n", status);
        sleep(3);
    }
    else
    {
	 wait(&status);
        printf("Oh, it's all better now\n");
	printf("%d\n", status);
    }
    return (0);
}
