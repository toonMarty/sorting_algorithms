#ifndef SORT_H
#define SORT_H

#include <stddef.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *add_dnodeint(listint_t **head, const int n);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void partition(int *array, int lower, int upper);
void quick_sort_recursive(int *array_init,
		size_t size_init, int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap(int *array, int first, int second);
void cocktail_sort_list(listint_t **list);
void swap_left_to_right(listint_t **list, listint_t *head, listint_t *aux);
void swap_right_to_left(listint_t **list, listint_t *head, listint_t *aux);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, int *right, size_t size);
void heap_sort(int *array, size_t size);
void check_tree(int *array, size_t size_init, size_t size, size_t i);
void radix_sort(int *array, size_t size);
int largest(int *array, size_t size);
#endif


