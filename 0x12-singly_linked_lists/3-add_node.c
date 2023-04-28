#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to the head of the list
 * @str: string to be stored in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str);
{
		list_t *temp, *temp2;
	unsigned int length = 0;

	if (str == NULL)
		return (NULL);

	temp1 = malloc(sizeof(list_t));
	if (temp1 == NULL)
		return (NULL);

	temp1->str = strdup(str);
	if (temp1->str == NULL)
	{
		free(temp);
		return (NULL);
	}
	while (str[length])
		length++;
	temp1->len = length;
	temp1->next = NULL;

	if (*head == NULL)
	{
		*head = temp1;
		return (temp1);
	}
	temp2 = *head;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp;
	return (temp);
}
