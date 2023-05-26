#include "main.h"

/**
 * execmd - Executes commnands
 *
 * @argv: array of arguments
 *
 * Return: 0 success
 */

int execmd(char **argv)
{
	char *cmd, *cmdActual;
	pid_t pid;
	int status;
	static char *cd;

	cmd = argv[0];
	if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(cmd, "pwd") == 0)
	{
		printf("%s\n", getcwd(cd, 1024));
	}
	else
	{
		cmdActual = location(cmd);
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
		}
		else if (pid == 0)
		{
			if (execv(cmdActual, argv) == -1)
			{
				perror("Error:");
				return (1);
			}
		}

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error: ");
			return (1);
		}

		free(cmdActual);
	}
	return (0);
}
