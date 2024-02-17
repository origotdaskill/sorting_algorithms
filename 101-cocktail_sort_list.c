#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @left: Pointer to the left node to be swapped
 * @right: Pointer to the right node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	right->prev = left->prev;
	left->prev = right;
	left->next = right->next;
	right->next = left;
	if (left->next)
	left->next->prev = left;
}

/**
 * cocktail_forward - Performs forward iteration of the Cocktail shaker sort
 * @list: Pointer to the head of the doubly linked list
 * @end: Pointer to the end of the sorted portion of the list
 *
 * Return: 1 if a swap occurred, 0 otherwise
 */
int cocktail_forward(listint_t **list, listint_t *end)
{
	listint_t *start = *list;
	int swapped = 0;

	while (start->next != end)
	{
		if (start->n > start->next->n)
		{
			swap_nodes(list, start, start->next);
			start = start->prev;
			swapped = 1;
			print_list(*list);
		}
		else
		{
		start = start->next;
		}
	}

	return swapped;
}

/**
 * cocktail_backward - Performs backward iteration of the Cocktail shaker sort
 * @list: Pointer to the head of the doubly linked list
 * @end: Pointer to the end of the sorted portion of the list
 *
 * Return: 1 if a swap occurred, 0 otherwise
 */
int cocktail_backward(listint_t **list, listint_t *end)
{
	listint_t *start = end;
	int swapped = 0;

	while (start->prev != NULL)
	{
		if (start->n < start->prev->n)
		{
			swap_nodes(list, start->prev, start);
			start = start->next;
			swapped = 1;
			print_list(*list);
		}
		else
		{
			start = start->prev;
		}
	}

	return swapped;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list, *end = NULL;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		swapped |= cocktail_forward(list, end);
	if (!swapped)
		break;
	end = start;
        swapped |= cocktail_backward(list, end);
	} while (swapped);
}
