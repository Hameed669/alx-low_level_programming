#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Pointer to a pointer to the head node of the list.
 * @n: Integer value to store in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp1, *temp2;

	temp1 = malloc(sizeof(listint_t));

	if (temp1 == null)
		return (NULL);

	temp1->n = n;
	temp2 = *head;

	while (temp2 != NULL && temp2->next != NULL)
	{
		temp2 = temp2->next;
	}

	if (temp2 == NULL)
	{
		*head = temp1;
	}
	else
	{
		temp2->next = temp1;

	}

	return (temp1);
}
