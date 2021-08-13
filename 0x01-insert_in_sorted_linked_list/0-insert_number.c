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
    listint_t *newb, *temp = *head;

    /* making space */
    newb = malloc(sizeof(listint_t));

    /* if nothing is passed free it */
    if (newb == NULL)
    {
        free (newb);
        return (NULL);
    }
    newb->n = number;
    /* empty list */
    if (*head == NULL)
    {
        *head = newb;
        return newb;
    }
    /* add node to the beginning */
    if (number < temp->n)
    {
        newb->next = temp;
        *head = newb;
        return newb;
    }
    /* loop through and start comparing values */
    else
    {
        for (temp = *head; temp->next && temp->next->n < number; temp = temp->next);
        {
            /* add to end */
            if (temp->next == NULL)
            {
                temp->next = newb;
                newb->next = NULL;
                return newb;
            }
            /* if they are equal */
            else if (temp->next->n == number)
            {
                newb->next = temp->next;
                temp->next = newb;
                return newb;

            }
            /* add new number before big numb */
            else if (temp->next->n > number)
            {
                newb->next = temp->next;
                temp->next = newb;
                return newb;
            }
        }
    }
    free (newb);
    return (NULL);
}