#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *tmp;

	if (head == NULL || *head == NULL)
		return (-1);

	for (i = 0; i < index; i++)
	{
		if ((*head)->next == NULL)
			return (-1);
		*head = (*head)->next;
	}

	if ((*head)->prev != NULL)
		(*head)->prev->next = (*head)->next;

	if ((*head)->next != NULL)
		(*head)->next->prev = (*head)->prev;

	tmp = *head;

	if ((*head)->prev != NULL)
		*head = (*head)->prev;
	else
		*head = (*head)->next;

	free(tmp);

	while (*head != NULL && (*head)->prev != NULL)
		*head = (*head)->prev;

	return (1);
}
