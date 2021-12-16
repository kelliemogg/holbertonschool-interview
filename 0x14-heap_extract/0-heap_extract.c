#include "binary_trees.h"

/**
* heap_extract - extract the root of a heap
* @root: double pointer to the root of the heap
* description: return the value stored in the root node
* then free the root node and replace with the last
* level-order node of the heap. Then, re-heapify the heap
* Return: the value stored in the root node
*/

int heap_extract(heap_t **root)
{
    heap_t *temp;
    int value;

    if (!root || !*root)
        return (0);

    temp = *root;
    value = temp->n;
    *root = temp->left;
    free(temp);
    if (*root)
        heapify(*root);
    return (value);
}

/**
* heapify - re-heapify the heap
* @root: pointer to the root of the heap
* description: re-heapify the heap
* Return: void
*/
void heapify(heap_t *root)
{
    heap_t *temp;

    while (root->left)
    {
        if (root->n < root->left->n)
        {
            temp = root->left;
            root->left = temp->left;
            temp->left = root;
            root = temp;
        }
        else
            break;
    }
}
