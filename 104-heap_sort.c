#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Performs sift-down operation on a max heap
 * @array: Array representing the heap
 * @start: Index of the root of the subtree
 * @end: Index of the last element in the heap
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;

	while (root * 2 + 1 <= end)
	{
		size_t child = root * 2 + 1;
		size_t swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx != root)
		{
			swap(&array[root], &array[swap_idx]);
			print_array(array, size);
			root = swap_idx;
		}
		else
		{
			return;
		}
	}
}

/**
 * heapify - Builds a max heap from an array
 * @array: The array to be heapified
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	size_t i;

	for (i = (size - 1) / 2; i > 0; i--)
		sift_down(array, i, size - 1, size);
	sift_down(array, 0, size - 1, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending using Heap sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;


	if (array == NULL || size < 2)
		return;


	heapify(array, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
