#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array
 * @array: The original array containing the subarrays
 * @left: The left subarray
 * @right: The right subarray
 * @size_l: The size of the left subarray
 * @size_r: The size of the right subarray
 **/
void merge(int *array, int *left, int *right, size_t size_l, size_t size_r)
{
    size_t i = 0, j = 0, k = 0;
    int *tmp = malloc(sizeof(int) * (size_l + size_r));

    if (!tmp)
        return;

    printf("Merging...\n[left]: ");
    print_array(left, size_l);
    printf("[right]: ");
    print_array(right, size_r);

    while (i < size_l && j < size_r)
    {
        if (left[i] <= right[j])
            tmp[k++] = left[i++];
        else
            tmp[k++] = right[j++];
    }

    while (i < size_l)
        tmp[k++] = left[i++];
    while (j < size_r)
        tmp[k++] = right[j++];

    for (i = 0; i < size_l + size_r; i++)
        array[i] = tmp[i];

    printf("[Done]: ");
    print_array(array, size_l + size_r);

    free(tmp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 **/
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t middle = size / 2;
        int *left = array;
        int *right = array + middle;
        size_t size_l = middle;
        size_t size_r = size - middle;

        merge_sort(left, size_l);
        merge_sort(right, size_r);
        merge(array, left, right, size_l, size_r);
    }
}
