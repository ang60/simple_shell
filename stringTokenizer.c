#include "main.h"

#define DELIM " \t\r\n\a"

/**
 * stringTokenizer - splits arguments to tokens
 *
 * @arguments: command
 * Return: split arguments
 */

char **stringTokenizer(char *arguments)
{
	char *copy, *token, **args;
	int argCounter, i;

	copy = strdup(arguments);

	if (copy == NULL)
	{
		perror("Error: ");
		return (NULL);
	}

	argCounter = 0;
	token = strtok(copy, DELIM);

	while (token != NULL)
	{
		argCounter++;
		token = strtok(NULL, DELIM);
	}
	args = calloc(argCounter + 1, sizeof(char *));

	if (args == NULL)
	{
		perror("Error: ");
		free(copy);
		return (NULL);
	}
	i = 0;
	token = strtok(arguments, DELIM);
	while (token != NULL)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, DELIM);
	}
	args[i] = NULL;
	free(copy);

	return (args);
}
