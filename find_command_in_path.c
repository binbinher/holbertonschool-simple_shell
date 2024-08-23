#include "shell.h"

/**
 * find_command_in_path - Searches for a command in the PATH
 * @command: The command to search for
 * Return: The full path to the command if found, NULL otherwise
 */
char *find_command_in_path(const char *command)
{
	char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *dir = strtok(path_copy, ":");
	char *full_path = NULL;

	if (dir != NULL && strncmp("/bin/", command, 5) == 0)
	{
		full_path = malloc(strlen(command) + 6);
		sprintf(full_path, "/usr%s", command);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		else
			return (NULL);
	}
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
