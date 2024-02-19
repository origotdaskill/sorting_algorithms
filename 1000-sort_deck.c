#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * card_cmp - Compares two cards for sorting
 * @ptr1: Pointer to the first card
 * @ptr2: Pointer to the second card
 * Return: Integer less than, equal to, or greater than zero if the first
 * card is found, respectively, to be less than, to match, or be greater than
 * the second card.
 */
int card_cmp(const void *ptr1, const void *ptr2)
{
    const card_t *card1 = (*((const deck_node_t **)ptr1))->card;
    const card_t *card2 = (*((const deck_node_t **)ptr2))->card;

    int value_cmp = strcmp(card1->value, card2->value);
    if (value_cmp != 0)
        return value_cmp;

    return card1->kind - card2->kind;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the doubly linked list representing the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current;
    deck_node_t *temp;
    size_t i, j;
    size_t count = 0;

    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    current = *deck;
    while (current)
    {
        current = current->next;
        count++;
    }

    for (i = 0; i < count - 1; i++)
    {
        current = *deck;
        for (j = 0; j < count - i - 1; j++)
        {
            if (current->card->kind > current->next->card->kind ||
                (current->card->kind == current->next->card->kind &&
                 strcmp(current->card->value, current->next->card->value) > 0))
            {
                temp = current->next->next;
                current->next->next = current;
                current->next->prev = current->prev;
                current->prev = current->next;
                current->next = temp;
                if (temp)
                    temp->prev = current;
                if (current->prev)
                    current->prev->next = current->prev->next == current ? current->next : current;
                if (current == *deck)
                    *deck = current->prev;
            }
            else
            {
                current = current->next;
            }
        }
    }
}
