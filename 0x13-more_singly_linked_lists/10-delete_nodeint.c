#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t list.
 * @head: double pointer to the head node of the list.
 * @index: index of the node to be deleted.
 *
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	current = *head;
	previous = NULL;

	for (i = 0; current != NULL && i < index; i++)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		return (-1);

	if (previous == NULL)
		*head = current->next;
	else
		previous->next = current->next;

	free(current);
	return (-1);
}
