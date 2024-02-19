#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the pointer to the head node of the list
 * @n1: Pointer to the first node
 * @n2: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t **n1, listint_t **n2)
{
    listint_t *prev_n1 = (*n1)->prev;
    listint_t *next_n2 = (*n2)->next;

    if (prev_n1)
        prev_n1->next = *n2;
    else
        *list = *n2;
    if (next_n2)
        next_n2->prev = *n1;

    (*n1)->prev = *n2;
    (*n2)->next = *n1;
    (*n1)->next = next_n2;
    (*n2)->prev = prev_n1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail shaker sort algorithm
 * @list: Pointer to the pointer to the head node of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start = *list;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    

    do {
        swapped = 0;
        for (current = start; current != NULL && current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &(current->next));
                print_list(*list);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (; current != NULL && current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &(current->prev), &current);
                print_list(*list); 
                swapped = 1;
            }
        }
        start = start->next;
    } while (swapped && start != NULL);
}
