#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @lst: Pointer to a pointer to the head of the list.
 * @A1: Pointer to a pointer to the first node to be swapped.
 * @B2: Pointer to the second node to be swapped.
 * Return : Nothing
 */
void swap_nodes(listint_t **lst, listint_t **A1, listint_t *B2)
{
	(*A1)->next = B2->next;
	if (B2->next != NULL)
		B2->next->prev = *A1;
	b2->prev = (*A1)->prev;
	b2->next = *A1;
	if ((*A1)->prev != NULL)
		(*A1)->prev->next = B2;
	else
		*lst = B2;
	(*A1)->prev = B2;
	*A1 = B2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: Pointer to a pointer to the head of the list.
 * Return : Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lst, *isr, *ins;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (lst = (*list)->next; lst != NULL; lst = ins)
	{
		ins = lst->next;
		isr = lst->prev;
		while (isr != NULL && lst->n < isr->n)
		{
			swap_nodes(list, &isr, lst);
			print_list((const listint_t *)*list);
		}
	}
}
