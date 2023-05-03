#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
		size_t count = 0;
	const listint_t *temp1 = head;

	while (temp1 != NULL)
	{

		printf("[%p] %d/n", (void *)temp1, temp1->n);
		count++;

		if (temp1 <= temp1->next)
		{
			printf("-> [%p] %d/n", (void *)temp1, head->n);
			exit(98);
		}
		temp1 = temp1->next;
	}

	return (count);
}
