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
	char **args = malloc(sizeof(char *) * MAX_ARGS);
	char *command_path;
	int num_args, result;

	while (1)
	{
		print_prompt();
		num_of_read = read_command(&line, &len);
		result = handle_input(&line, num_of_read);
		if (result == 1)
			break;
		else if (result == 2)
		{
			print_env();
			continue;
		}
		num_args = tokenize_command(line, args, MAX_ARGS);
		if (num_args > 0)
		{
			command_path = find_command_in_path(args[0]);
			if (command_path != NULL)
			{
				execute_command(command_path, args);
				free(command_path);
			}
			else
				printf("%s: command not found\n", args[0]);
		}
		else
		{
			printf("No valid command entered\n");
		}
	}
	free(line);
	free(args);
	return (0);
}
