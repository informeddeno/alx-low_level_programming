#include "lists.h"
/**
 * delete_nodeint_at_index - delete a node in  linked list index
 * @head: pointer to the first element
 * @index: index of the node to delete
 * Return: 1 (Success) or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *new = *head;
listint_t *temp = NULL;
unsigned int i = 0;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;
free(new);
return (1);
}

while (i < index - 1)
{
if (!new || !(temp->next))
return (-1);
new = new->next;
i++;
}
temp = new->next;
new->next = temp->next;
free(temp);
return (1);
}
