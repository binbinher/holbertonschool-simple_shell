#include "shell.h"
/**
 * main - Entry Point to Shell
 * @line: pointer to hold the input line
 * @len: variable to hold the buffer size.
 * @num_of_read:variable to store the number of characters read.
 * @args: an array to stroe the tokenized arguments
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
		printf("Please enter your command >");
		num_of_read = getline(&line, &len, _stdin);
		if (num_of_read == -1)
		{
			perror("getline failed");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (num_of_read > 0 && line[num_of_read - 1] == '\n')
		{
			line[num_of_read - 1] = '\0';
		}

		if (_strcmp(line, "exit") == 0)
		{
			break;
		}

		int num_args = tokenize_command(line, args);

		return (0);
	}
