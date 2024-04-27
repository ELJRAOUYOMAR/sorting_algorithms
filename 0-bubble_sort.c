#include "sort.h"

/**
 * sorts an array of integers in ascending order using the Bubble sort algorithm
 * @array: an array of integers will be sorted
 * @size: the number of elements in the array
 * 
 * print the array after each time you swap two elements
*/
void bubble_sort(int *array, size_t size)
{
    int temp;
    size_t i, j;

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