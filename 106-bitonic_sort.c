#include "sort.h"
#include <stdio.h>

void swap(int *a, int *b);
void merge_bitonic(int *array, size_t size, size_t start, size_t seq,
                   char flow);
void build_bitonic(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * merge_bitonic - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void merge_bitonic(int *array, size_t size, size_t start, size_t seq,
                   char flow)
{
    size_t i, jump = seq / 2;

    if (seq > 1)
    {
        for (i = start; i < start + jump; i++)
        {
            if ((flow == 'U' && array[i] > array[i + jump]) ||
                (flow == 'D' && array[i] < array[i + jump]))
                swap(&array[i], &array[i + jump]);
        }
        merge_bitonic(array, size, start, jump, flow);
        merge_bitonic(array, size, start + jump, jump, flow);
    }
}

/**
 * build_bitonic - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void build_bitonic(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t cut = seq / 2;
    char *str = (flow == 'U') ? "UP" : "DOWN";

    if (seq > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);

        build_bitonic(array, size, start, cut, 'U');
        build_bitonic(array, size, start + cut, cut, 'D');
        merge_bitonic(array, size, start, seq, flow);

        printf("Result [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);
    }
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    build_bitonic(array, size, 0, size, 'U');
}

