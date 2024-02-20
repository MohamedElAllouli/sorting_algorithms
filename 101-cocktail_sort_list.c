#include "sort.h"
/**
 *swap_node_helper - swap a node for his previous one
 *@node: node
 *@list: list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node_helper(listint_t *node, listint_t **list)
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
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node_helper(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node_helper(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
