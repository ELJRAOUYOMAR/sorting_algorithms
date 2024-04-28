#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using Bubble sort
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

<<<<<<< HEAD
    if (!array || !size)
        return;
    
    i = 0;
    while (i < size)
    {
        for(j = 0; j < size - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
            }
        }
    }
}
=======
	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
>>>>>>> 363322f59fdb2b065cad945b05b46dc5d5a345c5
