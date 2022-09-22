#include "sort.h"

/**
 * swap_left_to_right - swaps nodes from  left to  right
 * @list: a double pointer to a list
 * @head: a pointer to a head node
 * @aux: a helper pointer
 * Return: nothing
 */

void swap_left_to_right(listint_t **list, listint_t *head, listint_t *aux)
{
	if (head->prev)
		head->prev->next = aux;
	else
		*list = aux;
	if (aux->next)
		aux->next->prev = head;
	head->next = aux->next;
	aux->prev = head->prev;
	aux->next = head;
	head->prev = aux;
	print_list(*list);
}

/**
 * swap_right_to_left - swaps nodes from right to left
 * @list: a double pointer to a linked list
 * @head: a pointer to  the head node
 * @aux: an auxiliary pointer
 * Return: nothing
 */
void swap_right_to_left(listint_t **list, listint_t *head, listint_t *aux)
{
	aux = head->prev;
	aux->next->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	else
		*list = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
	print_list(*list);
}
/**
 * cocktail_sort_list - a function that sorts a doubly linked
 * list of integers in ascending order using the Cocktail shaker sort
 * algorithm
 * @list: a double pointer to a list
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int flag = 1;

	if (list)
	{
		head = *list;
		while (flag != 0)
		{
			flag = 0;
			while (head->next)
			{
				if (head->n > head->next->n)
				{
					aux = head->next;
					swap_left_to_right(list, head, aux);
					flag = 1;
				}
				else
					head = head->next;
			}
			if (flag == 0)
				break;
			flag = 0;
			while (head->prev)
			{
				if (head->prev->n > head->n)
				{
					swap_right_to_left(list, head, aux);
					flag = 1;
				}
				else
					head = head->prev;
			}
		}
	}
}
