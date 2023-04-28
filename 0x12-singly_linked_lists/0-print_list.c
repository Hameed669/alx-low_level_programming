#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * print_list - print all the element of a list_t list.
 * @h: pointer to the head of the list.
 *
 * Return: numbers of node in the list.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str != NULL)
			printf("[%u] %s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");

		count++;
		h = h->next;
	}

	return (count);
}
