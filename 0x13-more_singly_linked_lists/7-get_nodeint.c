#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to retrieve, starting from 0.
 *
 * Return: Pointer to the nth node of the list, or NULL if it doesn't exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *node = head;

	for (i = 0; node != NULL && i < index; i++)
		node = node->next;

	return (node);
}
