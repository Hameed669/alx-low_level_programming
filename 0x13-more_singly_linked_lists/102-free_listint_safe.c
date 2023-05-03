#include "lists.h"
#include <stdio.h>
/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to a pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int diff;
	listint_t *next;

	if (!h || !*h)
		return (0);

	while (*h)
	{

		diff = *h - (*h)->next;
		if (diff > 0)
		{
			next = (*h)->next;
			*h = next;
			len++;
		}
		else
		{
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}
