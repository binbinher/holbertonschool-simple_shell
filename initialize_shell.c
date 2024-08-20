#include "shell.h"
/**
 * initialize_shell - Initializes shell resources.
 * @line: pointer to hold the input.
 * @env_head: pointer to the linked list of environment variables.
 * Return: 0 on success, 1 on failure.
 */
int initialize_shell(char **line, list_t **env_head)
{
	*line = malloc(sizeof(char) * BUFF_SIZE);
	if (*line == NULL)
		return (1);

	*env_head = array_to_list(environ);
	if (*env_head == NULL)
	{
		free(*line);
		return (1);
	}
	return (0);
}
