#include "main.h"

/**
 * location - finds location from path
 *
 * @cmdInput: user input command 
 * Return: path or NULL on success
 */

char *location(char *cmdInput)
{
	char *envPath, *path, *cmdPath, *dir;
	size_t len;

	envPath = getenv("PATH");

	if (envPath == NULL)
	{
		return (NULL);
	}
	path = strdup(envPath);
	if (path == NULL)
	{
		return (NULL);
	}

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		len = strlen(dir) + 1 + strlen(cmdInput) + 1;
		cmdPath = malloc(len);
		if (cmdPath == NULL)
		{
			free(path);
			return (NULL);
		}
		snprintf(cmdPath, len, "%s/%s", dir, cmdInput);
		if (access(cmdPath, X_OK) == 0)
		{
			free(path);
			return (cmdPath);
		}
		free(cmdPath);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
