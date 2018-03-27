#include "header.h"

/**
 * fork_execute - fork a child and execute the command
 * @program: file to execute
 * @parameters: parameters/flags
 * @root_program: the calling program
 */

/*filename, args, argv[0]*/
void fork_execute(char *program, char **parameters, char *root_program)
{
	pid_t fork_ret = 0;
	int status = 0;

	fork_ret = fork();
	if (fork_ret < 0)
	{
		perror("Fork failed\n");
		exit(0);
	}
	if (fork_ret == 0)
	{
		if (*program == '\0')
		{
			exit(0);
		}
		if (execve(program, parameters, NULL) == -1)
			perror(root_program);

		exit(0);
	}
	else
		wait(&status);
}
