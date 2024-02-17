#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node_a: First node to be swapped
 * @node_b: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
    listint_t *prev_a, *next_a, *prev_b, *next_b;

    prev_a = node_a->prev;
    next_a = node_a->next;
    prev_b = node_b->prev;
    next_b = node_b->next;

    if (prev_a)
        prev_a->next = node_b;
    else
        *list = node_b;
    if (next_b)
        next_b->prev = node_a;

    node_a->prev = prev_b;
    node_a->next = next_b;
    node_b->prev = prev_a;
    node_b->next = next_a;

    if (next_a == node_b)
        node_a->next = node_b->next;
    if (prev_b == node_a)
        node_b->prev = node_a->prev;

    if (next_a)
        next_a->prev = node_a;
    if (prev_b)
        prev_b->next = node_b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *start, *end, *current;
    int swapped;

    if (list == NULL || *list == NULL)
        return;

    start = *list;
    end = NULL;
    do {
        swapped = 0;
        current = start;
        while (current->next != end) {
            if (current->n > current->next->n) {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
            current = current->next;
        }
        if (!swapped)
            break;
        swapped = 0;
        end = current;
        current = end->prev;
        while (current != start) {
            if (current->n > current->next->n) {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
            current = current->prev;
        }
        start = current->next;
    } while (swapped);
}
