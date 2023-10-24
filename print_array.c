#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - The function prints an array of integers
 * @array: The array to print
 * @size: The number of elements in the  @array
 */
void print_array(const int *array, size_t size)

{
	size_t x;

	x = 0;
	while (array && x < size)
	{
		if (x > 0)
			printf(", ");
		printf("%d", array[x]);
		++x;
	}
	printf("\n");
}
