#include "sort.h"
#include <stdlib.h>
/**
 * bubble_sort - sorts an array using the bubble sort
 * algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int pass, i, temp, swapped = 1;

	for (pass = size - 1; pass >= 0 && swapped; pass--)
	{
		swapped = 0;
		for (i = 0; i <= pass - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
