#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to a pointer to the head of the linked list.
 * @idx: Index of the list where the new node should be added.
 * Index starts at 0.
 * @n: Value to be assigned to the n field of the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp1, *temp2;
	unsigned int i = 0;

	if (*head == NULL && idx != 0)
		return (NULL);
	if (idx != 0)
	{
		temp2 = *head;
		for (; i < idx - 1 && temp2 != NULL; i++)
			temp2 = temp2->next;
		if (temp2 == NULL)
			return (NULL);
	}
	temp1 = malloc(sizeof(listint_t));
	if (temp1 == NULL)
		return (NULL);
	temp1->n = n;
	if (idx == 0)
	{
		temp1->next = *head;
		*head = temp1;
		return (temp1);
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
	return (temp1);
}

