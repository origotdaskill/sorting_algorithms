#include "sort.h"
#include <stdio.h>

/**
 * swap - change two values in ored
 * @arr: array
 * @item1: item one
 * @item2: item two
 * @order: 1- ascending, 0- descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}

/**
 * merge - sort bitonic sequence recursively in both orders
 * @arr: array
 * @low: first element
 * @nelement: element number
 * @order: 1-ascending, 0-descending order
 */
void merge(int arr[], int low, int nelement, int order)
{
	int mid, i;

	if (nelement > 1)
	{
		mid = nelement / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}

/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @nelement: number of element
 * @order: 1- ascending, 0-descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int low, int nelement, int order, int size)
{
	int mid;

	if (nelement > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i%i] (UP):\n", nelement, size);
			print_array(&arr[low], nelement);
		}
		else
		{
			printf("Merging [%i%i] (DOWN):\n", nelement, size);
			print_array(&arr[low], nelement);
		}
		mid = nelement / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelement, order);
		if (order <= 0)
		{
			printf("Result [%i%i] (DOWN):\n", nelement, size);
			print_array(&arr[low], nelement);
		}
		if (order >= 1)
		{
			printf("Result [%i%i] (UP):\n", nelement, size);
			print_array(&arr[low], nelement);
		}
	}
}

/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array length
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
