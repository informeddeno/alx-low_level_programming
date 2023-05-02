#include "lists.h"
/**
 * add_nodeint - add node at beginning of linked list
 * @head: pointer to first node in the list
 * @n: data to be inserted in new node
 * Return: pointer to new node or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *more;
more = malloc(sizeof(listint_t));
if (!more)
return (NULL);

more->n = n;
more->next = *head;
*head = more;
return (more);
}
