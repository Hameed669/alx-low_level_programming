#include "lists.h"

/**
 * sum_listint - Computes the sum of all the data in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The sum of all the data in the linked list,
 * or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *node;

	for (node = head; node != NULL; node = node->next)
		sum += node->n;

	return (sum);
}
