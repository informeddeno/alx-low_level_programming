#include "lists.h"
/**
 * get_nodeint_at_index – returns nth node of index in linked list
 * @head: first node in linked list
 * @index: index of  node to return
 * Return: pointer to nth node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i = 0;
listint_t *current = head;

while (current && i < index)
{
current = current->next;
i++;
}
return (current);
if (i > index)
return (NULL);
}
