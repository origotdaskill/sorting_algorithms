#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integersy
 * in ascending order using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *sorted_array;
	int max_value = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	counting_array = malloc(sizeof(int) * (max_value + 1));
	sorted_array = malloc(sizeof(int) * size);
	if (counting_array == NULL || sorted_array == NULL)
	{
		free(counting_array);
		free(sorted_array);
		return;
	}

	for (i = 0; i <= (size_t)max_value; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	for (i = 1; i <= (size_t)max_value; i++)
		counting_array[i] += counting_array[i - 1];

	for (i = 0; i < size; i++)
	{
		sorted_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
	array[i] = sorted_array[i];

	print_array(counting_array, max_value + 1);
	free(counting_array);
	free(sorted_array);
}
