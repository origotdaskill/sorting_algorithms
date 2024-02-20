#include "sort.h"
#include <stdio.h>

/**
 * _calloc - this is a calloc function
 * @nmemb: number of elements
 * @size: bit size of each element
 *
 * Return: pointer to memory assignment
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return ('\0');
	p = malloc(nmemb * size);
	if (!p)
		return ('\0');
	for (i = 0; i < (nmemb * size); i++)
		p[i] = '\0';
	return (p);
}

/**
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int index, maximum = 0, *counter = '\0', *tmp = '\0';
	size_t i;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > maximum)
		{
			maximum = array[i];
		}
	}
	counter = _calloc((maximum + 1), sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	for (index = 1; index <= maximum; index++)
		counter[index] += counter[index - 1];
	print_array(counter, (maximum + 1));
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}
