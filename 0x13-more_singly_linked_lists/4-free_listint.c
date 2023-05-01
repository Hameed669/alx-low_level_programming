#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Frees a list of integers.
 * @head: Pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
