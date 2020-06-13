#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: unordered int array
 * @size: array's size
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int swaped, tmp;
	unsigned int i;

	if (size < 2)
		return;

	do {
		swaped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swaped = 1;
				print_array(array, size);
			}
		}
	} while (swaped);
}
