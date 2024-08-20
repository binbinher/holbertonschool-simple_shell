#include "shell.h"
/**
 * main - Entry Point to Shell
 * @line: pointer to hold the input line
 * @len: variable to hold the buffer size.
 * @num_of_read: variable to store the number of characters read.
 * @args: an array to store the tokenized arguments
 * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t num_of_read;
	char *args[MAX_ARGS];

	while (1)
	{
		num_of_read = read_command(&line, &len);

		if (num_of_read == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}

		if (_strcmp(line, "exit") == 0)
		{
			break;
		}

		int num_args = tokenize_command(line, args);

		if (num_args > 0)
		{
			if (execute_command(args) == -1)
			{
				perror("Command execution failed!");
			}
		}
		else
		{
			perror("No valid command entered");
		}
	}

	free(line);
	return (0);
}
