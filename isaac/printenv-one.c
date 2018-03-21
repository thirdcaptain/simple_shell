#include <stdio.h>

extern char **environ;

int main(void)
{
	int i = 0;
	int j = 0;
	char *str;
	str = "PATH";
	printf("%s\n", *environ);
/*	while (environ[i])
	{
		printf("%s\n",environ[i]);
		i++;
	}
*/

	printf("WRONG!!!");
	printf("*environ[i]\n");
	printf("%c", *(environ[0]));
	printf("%c", *environ[1]);
	printf("%c", *environ[2]);
	putchar('\n');
	putchar('\n');
	putchar('\n');

	printf("(*environ)[i]\n");
	printf("%c", (*environ)[0]);
	printf("%c", (*environ)[1]);
	printf("%c", (*environ)[2]);
	printf("\n");
	putchar('\n');
	putchar('\n');

	printf("*environ[i][j]\n");
	printf("%c", environ[0][0]);
	printf("%c", environ[0][1]);
	printf("%c", environ[0][2]);
	putchar('\n');
	putchar('\n');
	putchar('\n');

	return(0);
}
