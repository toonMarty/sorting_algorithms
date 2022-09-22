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
	size_t d[1000], k = 0, j = 0, i;
	int n, j2;

	if (!array)
		return;
	while (j * 3 + 1 < size)
	{
		d[k] = j * 3 + 1;
		j = d[k++];
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((j + d[k - i - 1]) > size - 1)
				break;
			j2 = j;

			while (array[j2] > array[j2 + d[k - i - 1]])
			{
				n = array[j2];
				array[j2] = array[j2 + d[k - i - 1]];
				array[j2 + d[k - i - 1]] = n;
				j2 = j2 - d[k - i - 1];

				if (j2 < 0)
					break;
			}
		}
		print_array(array, size);
	}
}
