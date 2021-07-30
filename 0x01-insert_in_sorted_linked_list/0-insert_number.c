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
    listint_t *newb, *temp = *head, *hold;

    /* making space */
    newb = malloc(sizeof(listint_t));
    if (newb == NULL)
    {
        free (newb);
        return (NULL);
    }
    newb->n = number;
    if (number < temp->n)
    {
        newb->next = temp;
        *head = newb;
        return newb;
    }
    if (*head == NULL)
    {
        *head = newb;
        newb->next = NULL;
        return newb;
    }
        /* loop through and start comparing values */
    for (i = 0; temp != NULL; i++, temp = temp->next)
    {
        if (temp->n == number)
        {
            hold = temp->next;
            temp->next = newb;
            newb->next = hold;
            return newb;

        }
        if (temp->n > number)
        {
            if (temp->next == NULL)
            {
                temp->next = newb;
                newb->next = NULL;
                return newb;
            }
            else
            {
                hold = temp->next;
                temp->next = newb;
                newb->next = hold;
                return newb;
            }
        }
    }
    free (newb);
    return (NULL);
}