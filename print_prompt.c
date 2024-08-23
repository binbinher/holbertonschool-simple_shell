#include "shell.h"

/**
 * print_prompt - Displays the shell prompt to user.
 * Return: Nothing.
 */
void print_prompt(void)
{
	if (isatty(0))
	{
		printf("(HBTN shell)$ ");
		fflush(stdout);
	}
}
