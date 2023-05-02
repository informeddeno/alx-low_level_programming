#include "lists.h"
/**
 * free_listint2 - free linked list
 * @head: pointer to  listint_t list to free
 */
void free_listint2(listint_t **head)
{
listint_t *current;
if (head == NULL)
return;
while (*head)
{
current = (*head)->next;
free(*head);
*head = current;
}
*head = NULL;
}
