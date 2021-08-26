#include "lists.h"


/**
 * is_palindrome - checks if a single linked list is a palindrome
 * @head: points to the head of the linked list
 * 
 * Return: 0 or 1
 */

int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head;
	listint_t *second_half, *prev_slow = *head;
	listint_t *midnode = NULL;
	int res = 0;

	if (head != NULL)
	{
		while (fast != NULL && fast->next != NULL)
		{
			/* get to middle via slow compared to fast moving at double time */
			fast = fast->next->next;
			/* previous of slow node is for odd number of elements */
			prev_slow = slow;
			slow = slow->next;
		}
		if (fast != NULL)
		{
			midnode = slow;
			slow = slow->next;
		}
		/* Reverse second half and compare it */
		second_half = slow;
		prev_slow->next = NULL; /* NULL terminates first half */
		reverse(&second_half);
		res = compareLists(*head, second_half);

		reverse(&second_half);

		if (midnode != NULL)
		{
			prev_slow->next = midnode;
			midnode->next = second_half;
		}
		else
			prev_slow->next = second_half;
	}
	return (res);
}

void reverse (listint_t **head_ref)
{
	listint_t *prev = NULL;
	listint_t *current = *head_ref;
	listint_t *next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

int compareLists(listint_t *head, listint_t *head2)
{
	listint_t *temp1 = head;
	listint_t *temp2 = head2;

	while (temp1 && temp2)
	{
		if (temp1->n == temp2->n)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else return 0;
	}
	if (temp1 == NULL && temp2 == NULL)
		return 1;
	return 0;
}
