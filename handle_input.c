#include "shell.h"

/**
 * handle_input - Handles reading input from stdin
 * and processes end-of-file and errors.
 * @line: Pointer to hold the input line.
 * @num_of_read: Number of characters read.
 *
 * Return: 1 if 'exit' command is encountered, 0 otherwise.
 */

int handle_input(char **line, ssize_t num_of_read)
{
	if (num_of_read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(*line);
			exit(EXIT_SUCCESS);
		}
		perror("getline failed");
		free(*line);
		exit(EXIT_FAILURE);
	}

	if (_strcmp(*line, "exit") == 0)
	{
		return (1);
	}

	return (0);
}
