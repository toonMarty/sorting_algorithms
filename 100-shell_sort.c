#include "sort.h"
#include <stdlib.h>
/**
 * shell_sort - function that sorts an array
 * using the shell sort alogrithm
 * @array: the array to sort
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t in, out;
	size_t temp, h = 1;

	while (h <= size / 3)
	{
		h = (h * 3) + 1;
	}

	while (h > 0)
	{
		for (out = h; out < size; out++)
		{
			temp = array[out];
			in = out;

			while (in > (h - 1) && (size_t)(array[in - h]) >= temp)
			{
				array[in] = array[in - h];
				in = in - h;
			}
			array[in] = temp;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
