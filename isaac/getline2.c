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

	write(STDOUT_FILENO, "$ ", 2);
	characters = getline(&buffer, &bufsize, stdin);
	write(1, buffer, bufsize);
	free(buffer);

	return (0);
}
