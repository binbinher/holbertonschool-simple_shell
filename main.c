#include "shell.h"
/**
 * main - Entry Point to Shell
 * @line: pointer to hold the input line
 * @len: variable to hold the buffer size.
 * @numofread:variable to store the number of characters read.
 * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t numofread;

	while (1)
	{
		printf("Please enter your command >");
		numofread = getline(&line, &len, stdin);
		if (numofread == -1)
		{
			break;
		}

		printf("%s", line);
	}
	free(line);

	return (0);
}
