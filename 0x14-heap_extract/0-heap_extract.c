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

    if (*root)
        (*root)->parent = NULL;
    free(temp);
    if (*root)
        heapify(*root);
    return (value);
}

/**
* heapify - re-heapify the heap after extracting the root
* @root: pointer to the root of the heap
* description: re-heapify the heap after extracting the root
* and making the node to the left of the root the new root node
* Return: void
*/
void heapify(heap_t *root)
{
    heap_t *temp;

    while (root->left)
    {
        if (root->left->n < root->n)
        {
            if (root->right->n < root->n)
            {
                temp = root->left;
                root->left = root->right;
                root->right = temp;
            }
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        root = root->left;
    }
}
