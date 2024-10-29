#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked
 * list of integers in ascending order
 * using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (list == NULL || *list == NULL)
return;

current = (*list)->next;
while (current != NULL)
{
temp = current;
while (temp->prev != NULL && temp->n < temp->prev->n)
{
/* Swap nodes */
if (temp->prev->prev)
temp->prev->prev->next = temp;
if (temp->next)
temp->next->prev = temp->prev;
temp->prev->next = temp->next;
temp->next = temp->prev;
temp->prev = temp->prev->prev;
temp->next->prev = temp;

if (temp->prev == NULL)
*list = temp;

print_list(*list);
}
current = current->next;
}
}
