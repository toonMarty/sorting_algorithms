#include "sort.h"
#include <stdlib.h>

/**
 * selection_sort - function that sorts an array using
 * selection sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, min, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = 1;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
