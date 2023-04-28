#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - add a new node at the start of a list_t list
 * @head: pointer to pointer the head
 * @str: strings to be stored in a new node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = len;
	new->next = *head;
	*head = new;

	return (new);
}
