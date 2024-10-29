#include "sort.h"

/**
 * badilisha - inabadilisha thamani za int 2
 * @array: array ya int inayopangwa
 * @size: ukubwa wa array
 * @a: anwani ya thamani ya kwanza
 * @b: anwani ya thamani ya pili
 *
 * Return: void
 */
void badilisha(int *array, size_t size, int *a, int *b)
{
if (*a != *b)
{
*a = *a + *b;
*b = *a - *b;
*a = *a - *b;
print_array((const int *)array, size);
}
}

/**
 * sehemu_lomuto - inagawanya array
 * @array: array ya int inayopangwa
 * @size: ukubwa wa array
 * @lo: index ya chini ya eneo la kupangwa
 * @hi: index ya juu ya eneo la kupangwa
 *
 * Return: void
 */
size_t sehemu_lomuto(int *array, size_t size, ssize_t lo, ssize_t hi)
{
int i, j, pivot = array[hi];

for (i = j = lo; j < hi; j++)
if (array[j] < pivot)
badilisha(array, size, &array[j], &array[i++]);
badilisha(array, size, &array[i], &array[hi]);

return (i);
}

/**
 * kupangwa_haraka - inapanga kwa kutumia mpango wa kugawanya wa Lomuto
 * @array: array ya int inayopangwa
 * @size: ukubwa wa array
 * @lo: index ya chini ya eneo la kupangwa
 * @hi: index ya juu ya eneo la kupangwa
 *
 * Return: void
 */
void kupangwa_haraka(int *array, size_t size, ssize_t lo, ssize_t hi)
{
if (lo < hi)
{
size_t p = sehemu_lomuto(array, size, lo, hi);

kupangwa_haraka(array, size, lo, p - 1);
kupangwa_haraka(array, size, p + 1, hi);
}
}

/**
 * quick_sort - inaita kupangwa_haraka
 * @array: array ya int inayopangwa
 * @size: ukubwa wa array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
if (!array || !size)
return;
kupangwa_haraka(array, size, 0, size - 1);
}
