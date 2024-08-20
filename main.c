#include "shell.h"
/**
 * main - Entry Point to Shell
 * @line: pointer to hold the input line
 * @len: variable to hold the buffer size.
 * @num_of_read: variable to store the number of characters read.
 * @args: an array to store the tokenized arguments
 * @MAX_ARGS: the maximum number of command-line arguments.
 * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t num_of_read;
	char *args[MAX_ARGS];
	list_t *env_head = NULL;

	if (initialize_shell(&buffer, &env_head) != 0)
	{
		printf("Failed to initialize shell\n");
		return (1);
	}

	while (1)
	{
		print_prompt();

		num_of_read = read_command(&line, &len);

		if (handle_input(&line, num_of_read))
		{
			break;
		}

		int num_args = tokenize_command(line, args);

		if (num_args > 0)
		{
			execute_command(line, args);
		}

		else
		{
			perror("No valid command entered");
		}
	}

	free(line);
	free_list(env_head);
	return (0);
}
