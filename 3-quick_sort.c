#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @array: the array of integers
 * @a: the index of the first element
 * @b: the index of the second element
 * @size: the size of the array
 */
void swap(int *array, size_t a, size_t b, size_t size)
{
int temp = array[a];
array[a] = array[b];
array[b] = temp;
print_array(array, size);
}

/**
 * partition - partitions the array using Lomuto's scheme
 * @array: the array of integers
 * @low: the starting index
 * @high: the ending index
 * @size: the size of the array
 *
 * Return: the index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
swap(array, i, j, size);
}
}
swap(array, i + 1, high, size);
return (i + 1);
}

/**
 * quick_sort_recursive - recursively sorts the array
 * @array: the array of integers
 * @low: the starting index
 * @high: the ending index
 * @size: the size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = partition(array, low, high, size);
quick_sort_recursive(array, low, pi - 1, size);
quick_sort_recursive(array, pi + 1, high, size);
}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: the array of integers
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
quick_sort_recursive(array, 0, size - 1, size);
}
