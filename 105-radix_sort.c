#include "sort.h"

int getMax(int *array, int size);
void radixCountingSort(int *array, size_t size, int s, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * getMax - Finds the maximum element in an integer array.
 * @array: Pointer to the integer array.
 * @size: Size of the array.
 *
 * Return: The maximum value in the array.
 */
int getMax(int *array, int size)
{
	int m, i;

	for (m = array[0], i = 1; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	}

	return (m);
}

/**
* radixCountingSort - Counting sort for Radix Sort.
 * @array: Pointer to the array to be sorted.
 * @sim
