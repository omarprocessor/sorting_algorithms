#include "sort.h"
#include <unistd.h>

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
listint_t *current = *list, *next_node, *temp;

if (!list || !(*list))
return;

while (current)
{
next_node = current->next;
temp = current->prev;

while (temp && temp->n > current->n)
{

if (temp->next)
temp->next->prev = current;

current->prev = temp->prev;

if (temp->prev)
temp->prev->next = current;

temp->next = next_node;
if (next_node)
next_node->prev = temp;

if (!current->prev)
*list = current;

current->next = temp;
temp->prev = current;

temp = current->prev;
}
current = next_node;
}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the doubly linked list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (!node1 || !node2 || node1 == node2)
return;

if (node1->prev)
node1->prev->next = node2;
if (node2->next)
node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;

if (node1->next == node2)
{
node1->prev = node2;
node2->next = node1;
}
else
{
node1->prev = node2->prev;
node2->next = node1->next;

if (node2->next)
node2->next->prev = node2;
if (node1->next)
node1->next->prev = node1;
}

node2->prev = node1->prev;

if (!node2->prev)
*list = node2;

if (node1->next == NULL)
node1->next = NULL;
}
