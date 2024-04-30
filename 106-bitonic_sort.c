#include "sort.h"

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
void merge_bitonic(int *array, size_t size, size_t start_index, size_t sequence,
                   char direction)
{
    size_t i, jump = sequence / 2;

    if (sequence > 1)
    {
        for (i = start_index; i < start_index + jump; i++)
        {
            if ((direction == 'U' && array[i] > array[i + jump]) ||
                (direction == 'D' && array[i] < array[i + jump]))
                swap(&array[i], &array[i + jump]);
        }
        merge_bitonic(array, size, start_index, jump, direction);
        merge_bitonic(array, size, start_index + jump, jump, direction);
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
void build_bitonic(int *array, size_t size, size_t start_index, size_t sequence, char direction)
{
    size_t cut = sequence / 2;
    char *str = (direction == 'U') ? "UP" : "DOWN";

    if (sequence > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", sequence, size, str);
        print_array(array + start_index, sequence);

        build_bitonic(array, size, start_index, cut, 'U');
        build_bitonic(array, size, start_index + cut, cut, 'D');
        merge_bitonic(array, size, start_index, sequence, direction);

        printf("Result [%lu/%lu] (%s):\n", sequence, size, str);
        print_array(array + start_index, sequence);
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

