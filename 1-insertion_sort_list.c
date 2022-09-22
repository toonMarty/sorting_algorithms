#include "sort.h"
#include <stdlib.h>
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: double pointer to the doubly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head_temp1, *head_temp2, *aux1, *aux2;
	int flag;

	if (list)
	{
		head_temp1 = *list;
		head_temp2 = *list;
		while (list && head_temp1->next)
		{
			if (head_temp1->next)
			{
				flag = 0;
				head_temp2 = head_temp1;
				while (head_temp2 && head_temp2->n > head_temp2->next->n)
				{
					aux1 = head_temp2;
					aux2 = head_temp2->next;
					aux1->next = aux2->next;
					if (aux2->next)
						aux2->next->prev = aux1;
					if (aux2)
					{
						aux2->prev = aux1->prev;
						aux2->next = aux1;
					}
					if (aux1)
						aux1->prev = aux2;
					if (aux2->prev)
						aux2->prev->next = aux2;
					head_temp2 = aux2->prev;
					if (!aux2->prev)
						*list = aux2;
					print_list(*list);
					flag = 1;
				}
			}
			if (flag == 0)
				head_temp1 = head_temp1->next;
		}
	}
}
