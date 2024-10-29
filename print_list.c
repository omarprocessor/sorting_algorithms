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

/**
 * print_char - Prints a single character using write
 * @c: The character to print
 */
void print_char(char c)
{
write(1, &c, 1);
}

/**
 * print_number - Prints an integer using write
 * @n: The integer to print
 */
void print_number(int n)
{
char buffer[12];
int i = 11;
unsigned int num;

buffer[i--] = '\0';
num = (n < 0) ? -n : n;

if (n == 0)
buffer[i--] = '0';

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
if (n < 0)
buffer[i--] = '-';

write(1, &buffer[i + 1], 11 - i);
}
