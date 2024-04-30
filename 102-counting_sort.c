#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
    int max_number, *output, *count;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    max_number = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max_number)
            max_number = array[i];
    }

    /* Create and initialize the counting array */
    count = malloc((max_number + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (i = 0; i <= (size_t)max_number; i++)
        count[i] = 0;

    /* Count the occurrences of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Modify the counting array */
    for (i = 1; i <= (size_t)max_number; i++)
        count[i] += count[i - 1];

    /* Create the output array */
    output = malloc(size * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

    /* Fill the output array with sorted elements */
    for (i = 0; i < size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Print the sorted array */
    print_array(array, size);

    /* Free dynamically allocated memory */
    free(count);
    free(output);
}

