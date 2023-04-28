#include "lists.h"
#include <stdlib.h>

/**
 * list_len - return the number of the element in a list_t list
 * @h: pointer to the head of the list
 *
 * Return: number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
