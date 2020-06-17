#include "sort.h"

void quicksort(int *array, int bottom, int top, size_t size);
int split_array(int *array, int bottom, int top, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm - Lomuto partition scheme
 *
 * @array: unordered int array
 * @size: array's size
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - recursive function
 *
 * @array: unordered int array
 * @bottom: lowest index from splited array
 * @top: highest index from splited array
 * @size: array's size - used for printing
 *
 * Return: void
 */

void quicksort(int *array, int bottom, int top, size_t size)
{
	int pivot;

	if (bottom < top)
	{
		pivot = split_array(array, bottom, top, size);
		quicksort(array, bottom, pivot - 1, size);
		quicksort(array, pivot + 1, top, size);
	}
}

/**
 * split_array - split the array and return the pivot
 * Lomuto partition scheme
 *
 * @array: unordered int array
 * @bottom: lowest index from splited array
 * @top: highest index from splited array
 * @size: array's size
 *
 * Return: pivot
 */

int split_array(int *array, int bottom, int top, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[top];
	i = bottom;
	for (j = bottom; j < top; j++)
	{
		if (array[j] <= pivot)
		{
			if (j != i)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i = i + 1;
		}
	}
	if (j != i)
	{
		tmp = array[i];
		array[i] = array[top];
		array[top] = tmp;
		print_array(array, size);
	}
	return (i);
}
