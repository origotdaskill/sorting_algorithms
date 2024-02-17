/* 101-O */
/* Best case: O(n) */
/* Average case: O(n^2) */
/* Worst case: O(n^2) */

#include <stddef.h>
#include "sort.h"
#include <sys/types.h>


/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (!node1 || !node2)
        return;

    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    if (!node2->prev)
        *list = node2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail Shaker sort algorithm
 * @list: Pointer to pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *end = NULL; 
    int swapped = 1;
    listint_t *start = *list;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        while (start->next != end)
        {
            swapped = 0;
            end = start;

            if (start->n > start->next->n)
            {
                swap_nodes(list, start, start->next);
                swapped = 1;
                print_list(*list);
            }
            else
                start = start->next;
        }

        if (!swapped)
            break;

        while (start->prev != NULL)
        {
            if (start->n < start->prev->n)
            {
                swap_nodes(list, start->prev, start);
                swapped = 1;
                print_list(*list);
            }
            else
                start = start->prev;
        }
    }
}
