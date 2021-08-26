#include "lists.h"

/**
* is_palindrome - palindrome check on a linked list
* @head: pointer to the head of the list
* Return: 0 or 1
*/

int is_palindrome(listint_t **head)
{
	if (!*head)
		return (checkPalin(head, *head));
		return (1);
}

/**
* checkPalin - recursive function
* description: to check if a linked list is palindrome
* @head: pointer to the head of the list
* Return: 0 or 1
*/
int checkPalin(listint_t **left, listint_t *right)
{
	/* base case */
	if (!right)
		return (1);

	if (checkPalin(left, right->next) && (*left)->n == right->n)
	{
		(*left) = (*left)->next;
		return (1);
	}
	return (0);
}
