#include "sort.h"

int getMax(int *array, int size);
void radixCountingSort(int *array, size_t size, int s, int *buff);
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
	int x, y;

	for (x = array[0], y = 1; y < size; y++)
	{
		if (array[y] > x)
			x = array[y];
	}

	return (x);
}

/**
* radixCountingSort - Counting sort for Radix Sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @s: The current significant digit to sort on.
 * @buff: Temporary buffer for sorting.
 * Return : Nothing
 */
void radixCountingSort(int *array, size_t size, int s, int *buff)
{
	int coun[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t y;

	for (y = 0; y < size; y++)
		coun[(array[y] / s) % 10] += 1;

	for (y = 0; y < 10; y++)
		coun[y] += coun[y - 1];

	for (y = size - 1; (int)y >= 0; y--)
	{
		buff[coun[(array[y] / s) % 10] - 1] = array[y];
		coun[(array[y] / s) % 10] -= 1;
	}

	for (y = 0; y < size; y++)
		array[y] = buff[y];
}

/**
 * radix_sort - Sorts an array of integers using Radix Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return : Nothing.
 */
void radix_sort(int *array, size_t size)
{
	int x, s, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	x = getMax(array, size);
	for (s = 1; x / s > 0; s *= 10)
	{
		radixCountingSort(array, size, s, buff);
		print_array(array, size);
	}

	free(buff);
}
