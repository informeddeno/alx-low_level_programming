#include "lists.h"
/**
 * add_nodeint_end - add node at end of linked list
 * @head: pointer to first element in linked list
 * @n: new element data
 *
 * Return: pointer to new node or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *more;
listint_t *current = *head;

more = malloc(sizeof(listint_t));
if (!more)
return (NULL);

more->n = n;
more->next = NULL;

if (*head == NULL)
{
*head = more;
return (more);
}
while (current->next)
current = current->next;

current->next = more;

return (more);
}
