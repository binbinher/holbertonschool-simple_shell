#include "shell.h"
/**
 * tokenize_command - Tokenizes a command string into arguments
 * @command:the command string to tokenize
 * @args: an array to store the tokenized arguments
 * @maxargs: the max number of arguments
 * Return: the number of aruments parsed.
 */

int tokenize_command(char *command, char *args[], int maxargs)
{
	int i = 0;
	char *token;

	token = strtok(command, " ");

	while (token != NULL && i < maxargs - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	return (i);
}
