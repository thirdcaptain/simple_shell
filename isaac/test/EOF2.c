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
	int n = 0;

	while(1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == EOF)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		n = 0;
		while (buffer[n] != '\0')
		{
			if (buffer[n] == EOF)
				exit(1);
			printf("char:%c\n", buffer[n]);
			n++;
		}
		write(1, buffer, bufsize);
	}
	free(buffer);
	return (0);
}
