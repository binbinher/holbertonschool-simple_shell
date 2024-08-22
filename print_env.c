#include "shell.h"

/**
 * print_env - Prints the current environment variables.
 * Return : Nothing.
 */
void print_env(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
