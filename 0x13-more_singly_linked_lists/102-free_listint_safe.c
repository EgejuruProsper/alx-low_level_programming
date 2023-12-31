#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to a pointer to the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	current = *h;

	while (current != NULL)
	{
		count++;
		if (current->next >= current)
		{
			*h = NULL;
			return (count);
		}
		temp = current;
		current = current->next;
		free(temp);
	}

	*h = NULL;
	return (count);
}
