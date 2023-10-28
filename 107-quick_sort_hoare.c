#include "sort.h"

int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * swap_ints - The function swaps 2 integers in an array
 * @a: The 1st integer to swap
 * @b: The 2nd integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - The function orders a subset of an array of
 * integers according to the hoare partition scheme
 * @array: The integers’s array
 * @size: The array’s size
 * @left: The starting subset‘s index to order
 * @right: The ending subset‘s index to order
 * Return: The final partition index
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - The Implement the quicksort algorithm
 * through recursion
 * @array: The integers‘s array to sort
 * @size: The array’s size 
 * @left: The starting array’s index partition to order
 * @right: The ending array’s index partition to order
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - The function sorts an array of integers
 * in ascending order using the quicksort algorithm
 * @array: The integers’s array 
 * @size: The array’s size
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
