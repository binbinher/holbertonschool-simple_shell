#include "shell.h"

/**
 * execute_command - execute the given command and print error when needed
 * @line: pointer to hold the input line
 * @args: an array to store the tokenized arguments
 * Return: 0 if suceed -1 otherwise
 */
int execute_command(char *line, char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork creation failed");
		free(line);
		free_array(args);
		return (-1);
	}
	if (pid == 0)
	{
		/* a path sould be defined here */
		if (execve(NULL, args, NULL) == -1)/* NULL as to be changed by path & envp */
		{
			perror("Command execution failed!");
			free(line);
			free_array(args);
			exit(0);
		}
	}
	return (0);
}
