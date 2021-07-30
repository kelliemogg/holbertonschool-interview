#include "lists.h"

/**
 * insert_node - insert node in a linked list
 * @head: ptr to head
 * @number: int
 *
 * Description: insert an item
 */
listint_t *insert_node(listint_t **head, int number)
{
    int i;
    listint_t *newb, *temp = *head;

    /* making space */
    newb = malloc(sizeof(listint_t));
    if (newb == NULL)
    {
        free (newb);
        return (NULL);
    }
    newb->n = number;
    /* loop through and start comparing values */
    for (i = 0; temp != NULL; i++, temp = temp->next)
    {
        if (number < temp->n && temp->next != NULL)
        {
            listint_t *bigger = temp->next;
            temp->next = newb;
            newb->next = bigger;
            return newb;
        }
        else if (temp->n <= number && temp->next == NULL)
        {
            temp->next = newb;
            newb->next = NULL;
            return newb;
        }
    }
    free (newb);
    return (NULL);
}