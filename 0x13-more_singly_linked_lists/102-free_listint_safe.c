#include "lists.h"
#include <stdlib.h>
/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to a pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = *h;
	listint_t *next;

	while (current != NULL)
	{
		count++;
		next = current->next;

		free(current);
		current = NULL;

		if (next != NULL && next >= current)
			break;

		current = next;
	}

	*h = NULL;

	return (count);
}
