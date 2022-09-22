#include "sort.h"
#include <stdlib.h>

/**
 * largest - finds the largest array element
 * @array: a pointer to an array
 * @size: size of the array
 * Return: the largest array value
 */
int largest(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort - a function that sorts an array using the
 * Radix Sort algorithm
 * @array: a pointer to the array
 * @size: size of the array
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int *new;
	int i, max, e = 1;
	int t = size;

	if (!array || size < 2)
		return;
	max = largest(array, size);
	new = malloc(sizeof(int) * size);
	while (max / e > 0)
	{
		int b[20] = {0};

		i = 0;
		while (i < t)
		{
			b[(array[i] / e) % 10]++;
			i++;
		}
		if (b != NULL)
		{
			for (i = 1; i < 10; i++)
				b[i] += b[i - 1];
			for (i = t - 1; i >= 0; i--)
			{
				new[b[(array[i] / e) % 10] - 1] = array[i];
				b[(array[i] / e) % 10]--;
			}
			for (i = 0; i < t; i++)
				array[i] = new[i];
		}
		e *= 10;
		print_array(array, size);
	}
	free(new);
}
