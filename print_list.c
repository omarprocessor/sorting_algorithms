#include "sort.h"
#include <unistd.h>

void print_number(int n);
void print_char(char c);

/**
 * print_list - Prints a list of integers
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
int i = 0;

while (list)
{
if (i > 0)
print_char(','), print_char(' ');
print_number(list->n);
i++;
list = list->next;
}
print_char('\n');
}
