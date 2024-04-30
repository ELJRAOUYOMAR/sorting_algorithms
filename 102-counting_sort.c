#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int *output_arr, *indx_arr, max_value, j;
	size_t i, idx, val;

	if (!array || size < 2)
		return;

	max_value = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max_value)
			max_value = array[i];

	indx_arr = malloc(sizeof(int) * (max_value + 1));
	if (indx_arr == NULL)
		return;
	for (j = 0; j < max_value + 1; j++)
		indx_arr[j] = 0;

	for (i = 0; i < size; i++)
	{
		idx = array[i];
		++indx_arr[idx];
	}

	for (j = 1; j < max_value + 1; j++)
		indx_arr[j] += indx_arr[j - 1];
	print_array(indx_arr, max_value + 1);

	output_arr = malloc(sizeof(int) * size);
	if (output_arr == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		idx = array[i];
		val = indx_arr[idx]--;
		output_arr[val - 1] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output_arr[i];
	free(output_arr);
	free(indx_arr);
}
