#include "shell.h"

/**
 * execute_command - execute the given command and print error when needed
 * @command_path: path to the command
 * @args: an array to store the tokenized arguments
 * Return: 0 if suceed -1 otherwise
 */
int execute_command(char *command_path, char **args)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork creation failed");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror("Command execution failed!");
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
