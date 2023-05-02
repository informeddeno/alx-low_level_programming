#include "lists.h"
/**
 * sum_listint - returns sum of all data n in linked list
 * @head: first node in elements of linked list
 * Return: sum of data in linked list
 */
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *current = head;

while (current)
{
sum += current->n;
current = current->next;
}

return (sum);
}
