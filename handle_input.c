#include "shell.h"

/**
 * handle_input - Handles reading input from stdin
 * and processes end-of-file and errors.
 * @line: Pointer to hold the input line.
 * @num_of_read: Number of characters read.
 * @args: tokenized arguments
 * Return: 1 if 'exit' command is encountered, 0 otherwise.
 */

int handle_input(char **line, ssize_t num_of_read, char **args)
{
	if (num_of_read == -1)
	{
		free(*line);
		free(args);
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		perror("getline failed");
		exit(EXIT_FAILURE);
	}

	if ((_strcmp(*line, "exit\n")) == 0)
	{
		return (1);
	}
	else if ((_strcmp(*line, "env\n")) == 0)
	{
		return (2);
	}

	return (0);
}
