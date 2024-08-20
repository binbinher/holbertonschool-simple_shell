#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>

int _strcmp(const char *str1, const char *str2);
void free_array(char **array);

#endif
