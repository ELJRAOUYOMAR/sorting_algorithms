#include "sort.h"

void swap_ints(int *s, int *i);
int hoarePartition(int *array, size_t size, int let, int rgh);
void hoareSort(int *array, size_t size, int let, int rgh);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swaps the values of two integers.
 * @s: Pointer to the first integer.
 * @i: Pointer to the second integer.
 * Return : Nothing.
 */
void swap_ints(int *s, int *i)
{
	int tm;

	tm = *s;
	*s = *i;
	*i = tm;
}

/**
 * hoarePartition - Partitions an array using the Hoare partition scheme.
 * @array: Pointer to the array to be partitioned.
 * @size: Size of the array.
 * @let: Index of the left boundary for partitioning.
 * @rgh: Index of the right boundary for partitioning.
 *
 * Return: The final partition index.
 */
int hoarePartition(int *array, size_t size, int let, int rgh)
{
	int p, abo, blw;

	p = array[rgh];
	for (abo = let - 1, blw = rgh + 1; abo < blw;)
	{
		do {
			abo++;
		} while (array[abo] < 
