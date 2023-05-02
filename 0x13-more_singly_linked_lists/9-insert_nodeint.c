#include "lists.h"
/**
 * insert_nodeint_at_index - insert new node at given position
 * @head: pointer to the first node of elements
 * @idx: index of position to insert node
 * @n: data to insert in new node
 * Return: pointer to new node or NULL if failed or not possible to add node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int i;
listint_t *more;
listint_t *current = *head;

more = malloc(sizeof(listint_t));
if (!more || !head)
return (NULL);
more->n = n;
more->next = NULL;

if (idx == 0)
{
more->next = *head;
*head = more;
return (more);
}
for (i = 0; more && i < idx; i++)
{
if (i == idx - 1)
{
more->next = current->next;
current->next = more;
return (more);
}
else
current = current->next;
}
return (NULL);
}
