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
	if (!temp1)
		return (NULL);

	temp1->n = n;
	temp1->next = NULL;

	if (*head == NULL)
	{
		*head = temp1;
		return (temp1);
	}

	temp2 = *head;
	while (temp2->next)
		temp2 = temp2->next;

	temp2->next = temp2;

	return (temp2);
}
