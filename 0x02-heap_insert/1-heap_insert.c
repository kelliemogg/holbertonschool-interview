#include "binary_trees.h"

/**
* heap_insert - inserts a value into a Max Binary Heap
* @root: dbl ptr to the root node of the heap
* @value: value of the node to be inserted
* Return: ptr to the inserted node
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newb;
	heap_t *temp = *root;

	newb = malloc(sizeof(heap_t));

	/* null checks */
	if (!newb || !value)
		return (NULL);
	/* set value to new node */
	newb->n = value;
	newb->parent = NULL;
	newb->left = NULL;
	newb->right = NULL;

	if (*root == NULL)
	{
		*root = newb;
	}
	else
	{
		if (temp->n > newb->n)
		{
			newb->parent = temp;
			temp->right = newb;
		}
		else if (newb->n > temp->n)
		{
			newb->right = temp;
			newb = *root;
		}
	}
	return (newb);
}

/**
* swap - swaps node values
* @x: first value
* @y: second value
* Return: void
*/

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
