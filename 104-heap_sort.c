#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'.
 * @array: The array to sort.
 * @start: The starting index of the heap.
 * @end: The end index of the heap.
 * @size: The size of the array.
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child, swap;
    int tmp;

    while ((root * 2 + 1) <= end)
    {
        child = root * 2 + 1;  /* left child */
        swap = root;

        /* Find the largest child */
        if (array[swap] < array[child])
            swap = child;
        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;

        if (swap != root)
        {
            /* Swap root and largest child */
            tmp = array[root];
            array[root] = array[swap];
            array[swap] = tmp;
            print_array(array, size);
            root = swap;
        }
        else
            return;
    }
}

/**
 * heapify - Build a heap from the array.
 * @array: The array to sort.
 * @size: The size of the array.
 */
static void heapify(int *array, size_t size)
{
    size_t start;

    start = (size - 2) / 2; /* Start from the last non-leaf node */
    while (start + 1 > 0)
    {
        sift_down(array, start, size - 1, size);
        start--;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to sort.
 * @size: Number of elements in @array.
 */
void heap_sort(int *array, size_t size)
{
    size_t end = size - 1;
    int tmp;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    while (end > 0)
    {
        /* Swap the root (maximum value) of the heap with the last element */
        tmp = array[end];
        array[end] = array[0];
        array[0] = tmp;
        print_array(array, size);
        /* Reduce the size of the heap and restore the heap property */
        end--;
        sift_down(array, 0, end, size);
    }
}

