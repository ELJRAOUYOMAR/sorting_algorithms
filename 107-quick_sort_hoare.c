#include "sort.h"

void swap_ints(int *x, int *y);
int hoarePartition(int *array, size_t size, int lf, int rth);
void hoareSort(int *array, size_t size, int lf, int rth);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swaps the values of two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 * Return : Nothing.
 */
void swap_ints(int *x, int *y)
{
	int tm;

	tm = *x;
	*x = *y;
	*y = tm;
}

/**
 * hoarePartition - Partitions an array using the Hoare partition scheme.
 * @array: Pointer to the array to be partitioned.
 * @size: Size of the array.
 * @lf: Index of the left boundary for partitioning.
 * @rth: Index of the right boundary for partitioning.
 *
 * Return: The final partition index.
 */
int hoarePartition(int *array, size_t size, int lf, int rth)
{
	int p, abo, blw;

	p = array[rth];
	for (abo = lf - 1, blw = rth + 1; abo < blw;)
	{
		do {
			abo++;
		} while (array[abo] < p);
		do {
			blw--;
		} while (array[blw] > p);

		if (abo < blw)
		{
			swap_ints(array + abo, array + blw);
			print_array(array, size);
		}
	}

	return (abo);
}

/**
 * hoareSort - Sorts an array using QuickSort with the Hoare partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @lf: Index of the left boundary for sorting.
 * @rth: Index of the right boundary for sorting.
 * Return : Nothing.
 */
void hoareSort(int *array, size_t size, int lf, int rth)
{
	int pat;

	if (rth - lf > 0)
	{
		pat = hoarePartition(array, size, lf, rth);
		hoareSort(array, size, lf, pat - 1);
		hoareSort(array, size, pat, rth);
	}
}

/**
 * quick_sort_hoare - Sorts an array using QuickSort
 * with the Hoare partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return : Nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoareSort(array, size, 0, size - 1);
} 
