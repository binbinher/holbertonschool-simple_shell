#include "shell.h"

/**
 * free_array - free an entire array
 * @array: the array to free
 */
void free_array(char **array)
{
	int index;

	for (index = 0; array[index]; index++)
	{
		free(array[index]);
	}
}
