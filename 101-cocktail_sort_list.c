#include "sort.h"

void swap_node_ahead(listint_t **lst, listint_t **l, listint_t **s);
void swap_node_behind(listint_t **lst, listint_t **l, listint_t **s);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swaps a node with the node
 * ahead of it in a doubly linked list.
 * @lst: Pointer to the list's head.
 * @l: Pointer to the list's tail.
 * @s: Pointer to the node to be swapped.
 * Return : Nothing
 */
void swap_node_ahead(listint_t **lst, listint_t **l, listint_t **s)
{
	listint_t *tmp = (*s)->next;

	if ((*s)->prev != NULL)
		(*s)->prev->next = tmp;
	else
		*lst = tmp;
	tmp->prev = (*s)->prev;
	(*s)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *s;
	else
		*l = *s;
	(*s)->prev = tmp;
	tmp->next = *s;
	*s = tmp;
}

/**
 * swap_node_behind - Swaps a node with
 * the node behind it in a doubly linked list.
 * @lst: Pointer to the list's head.
 * @l: Pointer to the list's tail.
 * @s: Pointer to the node to be swapped.
 * Return : Nothing
 */
void swap_node_behind(listint_t **lst, listint_t **l, listint_t **s)
{
	listint_t *tmp = (*s)->prev;

	if ((*s)->next != NULL)
		(*s)->next->prev = tmp;
	else
		*l = tmp;
	tmp->next = (*s)->next;
	(*s)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *s;
	else
		*lst = *s;
	(*s)->next = tmp;
	tmp->prev = *s;
	*s = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 * Return : Nothing
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *l, *s;
	bool stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (l = *list; l->next != NULL;)
		l = l->next;

	while (stirred == false)
	{
		stirred = true;
		for (s = *list; s != l; s = s->next)
		{
			if (s->n > s->next->n)
			{
				swap_node_ahead(list, &l, &s);
				print_list((const listint_t *)*list);
				stirred = false;
			}
		}
		for (s = s->prev; s != *list;
				s = s->prev)
		{
			if (s->n < s->prev->n)
			{
				swap_node_behind(list, &l, &s);
				print_list((const listint_t *)*list);
				stirred = false;
			}
		}
	}
}
