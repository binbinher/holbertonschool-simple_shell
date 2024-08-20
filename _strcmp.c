#include "shell.h"

/**
 * _strcmp - take two string and compare them
 * @str1: first string
 * @str2: second string
 * Return: 0 if both string are equql
 *		a positive value if the first string is greater
 *		a negative value otherwise
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
