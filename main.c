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
	pid_t pid;

	while (1)
	{
		printf("Please enter your command >");
		num_of_read = getline(&line, &len, stdin);

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

		if (num_args <= 0)
		{
			perror("No valid command entered");
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("Fork creation failed");
			free(line); /* should look if i didn't freed something */
			free_array(args);
			return (1);
		}
		if (pid == 0)
		{
			/* a path sould be defined here */
			if (execve(NULL, args, NULL) == -1) /* NULL values should be replaced bu path and envp */
			{
				perror("Command execution failed!");
				free(line);
				free_array(args);
				exit(0);
			}
		}
	}

	free(line);
	return (0);
}

void free_array(char **array)
{
	int index;

	for (index = 0; array[index]; index++)
	{
		free(array[index]);
	}
}