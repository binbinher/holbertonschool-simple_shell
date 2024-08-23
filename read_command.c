#include "shell.h"
/**
 * read_command - Reads a command from the user input.
 * @line: pointer to hold the input line.
 * @len: pointer to hold the buffer size.
 * Return: number of characters read, or -1 on failure.
 */

ssize_t read_command(char **line, size_t *len)
{
	ssize_t num_of_read;

	num_of_read = getline(line, len, stdin);

	if (num_of_read == -1)
	{
		/* perror("getline failed"); */
		exit(-1);
	}

	else if (num_of_read > 0 && (*line)[num_of_read - 1] == '\n')
	{
		(*line)[num_of_read - 1] = '\0';
	}

	return (num_of_read);
}
