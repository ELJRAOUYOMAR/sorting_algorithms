#include "sort.h"

/**
 * interchange - Swaps two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void interchange(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * merge_bitonic - Recursively merges bitonic sequences in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in the array to sort.
 * @seq: The size of the sequence to sort.
 * @direction: The direction to sort in ('U' for up, 'D' for down).
 */
void merge_bitonic(int *array, size_t size, size_t start_index, size_t sequence,
                   char sort_direction)
{
    size_t i, jump = sequence / 2;

    if (sequence > 1)
    {
        for (i = start_index; i < start_index + jump; i++)
        {
            if ((sort_direction == 'U' && array[i] > array[i + jump]) ||
                (sort_direction == 'D' && array[i] < array[i + jump]))
                interchange(&array[i], &array[i + jump]);
        }
        merge_bitonic(array, size, start_index, jump, sort_direction);
        merge_bitonic(array, size, start_index + jump, jump, sort_direction);
    }
}

/**
 * build_bitonic - Recursively builds bitonic sequences in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start_index: The starting index of a block of the bitonic sequence.
 * @sequence: The size of a block of the bitonic sequence.
 * @direction: The direction to sort the bitonic sequence block in ('U' for up, 'D' for down).
 */
void build_bitonic(int *array, size_t size, size_t start_index, size_t sequence, char bitonic_direction)
{
    size_t cut = sequence / 2;
    char *str = (bitonic_direction == 'U') ? "UP" : "DOWN";

    if (sequence > 1)
    {
        printf("Building [%lu/%lu] (%s):\n", sequence, size, str);
        print_array(array + start_index, sequence);

        build_bitonic(array, size, start_index, cut, 'U');
        build_bitonic(array, size, start_index + cut, cut, 'D');
        merge_bitonic(array, size, start_index, sequence, bitonic_direction);

        printf("Result [%lu/%lu] (%s):\n", sequence, size, str);
        print_array(array + start_index, sequence);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    build_bitonic(array, size, 0, size, 'U');
}

