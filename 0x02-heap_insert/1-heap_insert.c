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

	newb = malloc(sizeof(heap_t));

	/* null checks */
	if (!newb || !value)
		return (NULL);
	/* set value to new node */
	newb->n = value;
	
	if (*root == NULL)
	{
		*root = newb;
	}
	return (newb);
}
