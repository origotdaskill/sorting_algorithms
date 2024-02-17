#include "sort.h"
#include <sys/types.h>

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to be partitioned
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		int temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort
 * @array: Array to be sorted
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_recursive(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivot = lomuto_partition(array, size, low, high);

		quick_sort_recursive(array, size, low, pivot - 1);
		quick_sort_recursive(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *               using the Quick sort algorithm (Lomuto partition scheme)
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
