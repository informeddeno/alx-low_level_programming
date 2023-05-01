#include "lists.h"
/**
 * listint_len - returns number of elements in linked list
 * @h: linked list of type listint_t
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)

{
size_t item = 0;
while (h)
{
item++;
h = h->next;
}
return (item);
}
