#include "sort.h"

/**
 * dlistint_len - number of elements in a linked dlistint_t list.
 *
 * @h: head of double linked list
 *
 * Return: number of nodes
 */
size_t dlistint_len(listint_t *h)
{
	listint_t *current;
	size_t length = 0;

	if (h)
	{
		current = h;
		do {
			length++;
			current = current->next;

		} while (current);
	}
	return (length);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: unordered double linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	size_t len;
	listint_t *current, *insert, *aux;
	int insert_flag;

	len = dlistint_len(*list);
	if (len < 2)
		return;
	insert = (*list)->next;
	while (insert)
	{
		insert_flag = 1;
		current = insert;
		while (current->prev && current->n < current->prev->n)
		{
			if (insert_flag)
				insert = current->prev;
			insert_flag = 0;
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			if (current->prev->prev)
			{
				aux = current->prev->prev;
				current->prev->prev = current;
				current->next = current->prev;
				current->prev = aux;
				aux->next = current;
			}
			else
			{
				current->next = current->prev;
				current->prev->prev = current;
				current->prev = NULL;
				*list = current;
			}
			print_list(*list);
		}
		insert = insert->next;
	}
}
