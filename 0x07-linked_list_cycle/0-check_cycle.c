#include "lists.h"

/**
 * check_cycle - check for a cycle in a linked list
 * @list: the linked list
 * Return: 0 or 1
 **/

int check_cycle(listint_t *list)
{
    listint_t *slow_p = list, *fast_p;

    if (list == NULL)
        return 0;
    fast_p = list->next;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) 
        {
            return 1;
        }
    }
    return 0;
}
