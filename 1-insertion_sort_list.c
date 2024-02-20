#include "sort.h"
/**
 *swap_help - swap a node for his previous one
 *@node: node
 *@l: node list
 *Return: return a node which was enter it
 */
listint_t *swap_help(listint_t **l, listint_t *node)
{
	listint_t *b = node->prev, *tmpcurrent = node;

	b->next = tmpcurrent->next;
	if (tmpcurrent->next)
		tmpcurrent->next->prev = b;
	tmpcurrent->next = b;
	tmpcurrent->prev = b->prev;
	b->prev = tmpcurrent;
	if (tmpcurrent->prev)
		tmpcurrent->prev->next = tmpcurrent;
	else
		*l = tmpcurrent;
	return (tmpcurrent);
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp_node;
	
	if (list == NULL || (*list)->next == NULL)
		return;
	tmp_node = (*list)->next;
	while (tmp_node)
	{
		while ((tmp_node->prev) && (tmp_node->prev->n > tmp_node->n))
		{
			tmp_node = swap_help(list, tmp_node);
			print_list(*list);
		}
		tmp_node = tmp_node->next;
	}
}
