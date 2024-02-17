#include "sort.h"
#include <stdlib.h>

/**
 * create_count_array - Creates an array to store the count of each element
 * @array: The input array
 * @size: The size of the input array
 * @max: The maximum value in the input array
 * Return: The created count array
 */
int *create_count_array(int *array, size_t size, int max)
{
	int *count;
	size_t j;

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return (NULL);
	for (j = 0; j <= (size_t)max; j++)
		count[j] = 0;
	for (j = 0; j < size; j++)
		count[array[j]]++;
	return (count);
}

/**
 * create_temp_array - Creates a temporary array for sorting
 * @size: The size of the array
 * Return: The created temporary array
 */
int *create_temp_array(size_t size)
{
	return (malloc(size * sizeof(int)));
}

/**
 * update_count_array - Updates the count array to contain the numbersy
 * @count: The count array to be updated
 * @max: The maximum value in the array
 */
void update_count_array(int *count, int max)
{
	int d;

	for (d = 1; d <= max; d++)
		count[d] += count[d - 1];
}

/**
 * copy_sorted_elements - Copies sorted elements back into the original array
 * @array: The original array
 * @temp: The temporary array containing sorted elements
 * @size: The size of the array
 */
void copy_sorted_elements(int *array, int *temp, size_t size)
{
	size_t f;

	for (f = 0; f < size; f++)
		array[f] = temp[f];
}

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i;
	int *count, *temp;
	int k;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = create_count_array(array, size, max);
	if (count == NULL)
		return;

	update_count_array(count, max);
	temp = create_temp_array(size);
	if (temp == NULL)
	{
		free(count);
		return;
	}

	/* Place the elements in sorted order into the temporary array */
	for (k = size - 1; k >= 0; k--)
	{
		temp[count[array[k]] - 1] = array[k];
		count[array[k]]--;
	}

	copy_sorted_elements(array, temp, size);

	/* Print the counting array */
	print_array(count, max + 1);

	/* Free allocated memory */
	free(count);
	free(temp);
}
