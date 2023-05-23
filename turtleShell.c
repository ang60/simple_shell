#include "turtle.h"

/**
* turtleShell - runs the shell prompt and processes command
* @av: - argument vector
* @env: - enviroment variable
* Return - no return
*/
void turtleShell(char **av, char **env)
{
	char *command = NULL, *arga[COMMAND_COUNT];
	size_t n = 0;
	ssize_t  char_ret;
	int count, count2;
	pid_t childProcess;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("turtle$ ");
		char_ret = getline(&command, &n, stdin);
		if (char_ret == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		count = 0;
		while (command[count])
		{
			if (command[count] == '\n')
				command[count] = 0;
			count++;
		}
		arga[count2 = 0] = strtok(command, " ");
		while (arga[count2])
			arga[++count2] = strtok(NULL, " ");
		childProcess = fork();
		if (childProcess == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		if (childProcess == 0)
		{
			if (execve(arga[0], arga, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(NULL);
	}
}
