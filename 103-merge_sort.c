#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sub-arrays of array[]
 * @array: The array to be sorted
 * @left: Starting index of the first sub-array
 * @mid: Ending index of the first sub-array
 * @right: Ending index of the second sub-array
 * @tmp: Temporary array to store merged sub-arrays
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *tmp)
{
	size_t i, j, k;

	printf("[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid, k = 0; i < mid && j < right; k++)
	{
		if (array[i] < array[j])
			tmp[k] = array[i++];
		else
			tmp[k] = array[j++];
	}

	while (i < mid)
		tmp[k++] = array[i++];

	while (j < right)
		tmp[k++] = array[j++];

	for (i = left, k = 0; i < right; i++, k++)
		array[i] = tmp[k];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively divides and merges the sub-arrays
 * @array: The array to be sorted
 * @left: Starting index of the sub-array
 * @right: Ending index of the sub-array
 * @tmp: Temporary array to store merged sub-arrays
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *tmp)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(array, left, mid, tmp);
		merge_sort_recursive(array, mid, right, tmp);
		merge(array, left, mid, right, tmp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	merge_sort_recursive(array, 0, size, tmp);

	free(tmp);
}
