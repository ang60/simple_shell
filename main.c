#include "main.h"

/**
 * main - main function
 *
 * @ac:  arguments
 * @argv: arguments array
 * Return: 0 success
 */

int main(int ac, char **argv)
{
	char *cmdptr, **args;
	size_t cmdlen = 0;
	ssize_t getline_result;
	int i;

	while (1)
	{
		printf("%s", "$ ");
		getline_result = getline(&cmdptr, &cmdlen, stdin);
		if (getline_result == -1)
		{
			printf("Exit..\n");
			return (-1);
		}

		args = stringTokenizer(cmdptr);

		if (args == NULL)
		{
			continue;
		}

		execmd(args);

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);

		free(cmdptr);
		cmdptr = NULL;
		cmdlen = 0;
	}
	return (0);
	ac++;
	argv[i] = "l";
}
