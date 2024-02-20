#include "sort.h"

/**
 * swap_helper - swaps two nodes
 * @head: head of the list
 * @f_node: first node to sort
 * @s_node: second node to sort
 */
void swap_helper(listint_t **head, listint_t *f_node, listint_t *s_node)
{
	listint_t *prev, *next;

	prev = f_node->prev;
	next = s_node->next;

	if (prev != NULL)
		prev->next = s_node;
	else
		*head = s_node;
	f_node->prev = s_node;
	f_node->next = next;
	s_node->prev = prev;
	s_node->next = f_node;
	if (next)
		next->prev = f_node;
}
/**
 * cocktail_sort_list - sorts a list using the cocktail sort algorithm
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int flag = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap_helper(list, head, head->next);
				print_list(*list);
				flag = 1;
				head = head->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_helper(list, head->prev, head);
				print_list(*list);
				flag = 1;
				head = head->next;
			}
		}
	} while (flag == 1);
}
