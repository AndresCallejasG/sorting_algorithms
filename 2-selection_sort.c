#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: unordered int array
 * @size: array's size
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int tmp;
	unsigned int i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}