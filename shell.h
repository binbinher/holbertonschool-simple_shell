#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024
#define MAX_ARGS 100

/* helper functions: */

int handle_input(char **line, ssize_t num_of_read);
void print_prompt(void);
ssize_t read_command(char **line, size_t *len);
int tokenize_command(char *line, char **args);
char *find_command_in_path(const char *command);
int execute_command(char *line, char **args);
int _strcmp(const char *str1, const char *str2);
void free_array(char **array);

#endif
