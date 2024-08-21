#include "shell.h"
/**
 * main - Entry Point to Shell
 * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t num_of_read;
	char *args[MAX_ARGS];
	char *command_path;

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
			command_path = find_command_in_path(args[0]);
			if (command_path != NULL)
			{
				execute_command(line, args);
				free(command_path);
			}
			else
			{
				printf("%s: command not found\n", args[0]);
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
