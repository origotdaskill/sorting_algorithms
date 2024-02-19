#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Performs a bitonic merge on the given array
 * @array: The array to be sorted
 * @start: Starting index of the subarray to be sorted
 * @count: Number of elements in the subarray to be sorted
 * @dir: Sorting direction (ascending or descending)
 */
void bitonic_merge(int *array, size_t start, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = start; i < start + k; ++i)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

	bitonic_merge(array, start, k, dir);
	bitonic_merge(array, start + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively performs the bitonic sort
 * @array: The array to be sorted
 * @start: Starting index of the subarray to be sorted
 * @count: Number of elements in the subarray to be sorted
 * @dir: Sorting direction (ascending or descending)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		bitonic_sort_recursive(array, start, k, 1);
		bitonic_sort_recursive(array, start + k, k, 0);
		bitonic_merge(array, start, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
