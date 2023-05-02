#include "lists.h"
/**
 * free_listint - free linked list
 * @head: first listint_t element to free
 */
void free_listint(listint_t *head)
{
listint_t *current;

while (head)
{
current = head->next;
free(head);
head = current;
}
}
