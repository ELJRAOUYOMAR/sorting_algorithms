#include "sort.h"

void swap_node_ahead(listint_t **lst, listint_t **aiil, listint_t **sk);
void swap_node_behind(listint_t **lst, listint_t **aiil, listint_t **sk);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swaps a node with the node
 * ahead of it in a doubly linked list.
 * @lst: Pointer to the list's head.
 * @aiil: Pointer to the list's tail.
 * @sk: Pointer to the node to be swapped.
 * Return : Nothing
 */
void swap_node_ahead(listint_t **lst, listint_t **aiil, listint_t **sk)
{
	listint_t *tmp = (*sk)->next;

	if ((*sk)->prev != NULL)
		(*sk)->prev->next = tmp;
	else
		*lst = tmp;
	tmp->prev = (*sk)->prev;
	(*sk)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *sk;
	else
		*aiil = *sk;
	(*sk)->prev = tmp;
	tmp->next = *sk;
	*sk = tmp;
}

/**
 * swap_node_behind - Swaps a node with
 * the node behind it in a doubly linked list.
 * @lst: Pointer to the list's head.
 * @aiil: Pointer to the list's tail.
 * @sk: Pointer to the node to be swapped.
 * Return : Nothing
 */
void swap_node_behind(listint_t **lst, listint_t **aiil, listint_t **sk)
{
	listint_t *tmp = (*sk)->prev;

	if ((*sk)->next != NULL)
		(*sk)->next->prev = tmp;
	else
		*aiil = tmp;
	tmp->next = (*sk)->next;
	(*sk)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *sk;
	else
		*lst = *sk;
	(*sk)->next = tmp;
	tmp->prev = *sk;
	*sk = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 * Return : Nothing
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *aiil, *sk;
	bool stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (aiil = *list; aiil->next != NULL;)
		aiil = aiil->next;

	while (stirred == false)
	{
		stirred = true;
		for (sk = *list; sk != aiil; sk = sk->next)
		{
			if (sk->n > sk->next->n)
			{
				swap_node_ahead(list, &aiil, &sk);
				print_list((const listint_t *)*list);
				stirred = false;
			}
		}
		for (sk = sk->prev; sk != *list;
				sk = sk->prev)
		{
			if (sk->n < sk->prev->n)
			{
				swap_node_behind(list, &aiil, &sk);
				print_list((const listint_t *)*list);
				stirred = false;
			}
		}
	}
}
