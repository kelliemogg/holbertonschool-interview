#include "binary_trees.h"

/**
* heap_extract - extract the root of a heap
* @root: double pointer to the root of the heap
* description: return the value stored in the root node
* then free the root node and re-heapify the heap
* Return: the value stored in the root node
*/
int heap_extract(heap_t **root)
{
    int value, height;
    heap_t *temp;

    if (!root || !*root)
        return (0);

    temp = *root;
    value = temp->n;

    if (temp->left == NULL && temp->right == NULL)
    {
        *root = NULL;
    }
    else
    {
        height = binary_tree_height(temp, 1);
        temp = helper_heap_extract(*root, height, 1);
        (*root)->n = temp->n;
        if (temp->parent->right == temp)
            temp->parent->right = NULL;
        else
            temp->parent->left = NULL;
        heapify(*root);
    }
    free(temp);
    return (value);
}



/**
* binary_tree_height - return the height of a binary tree
* @root: pointer to the root of the tree
* @height: the height of root node
* description: return the height of the tree
* Return: the height of the tree
*/

int binary_tree_height(heap_t *root, int height)
{
    int left, right;
    if (!root)
        return (height - 1);
    height++;
    left = height = binary_tree_height(root->left, height);
    right = height = binary_tree_height(root->right, height);
    if (left > right)
        return (left);
    return (right);
}

/**
* heapify - re-heapify the heap
* @root: pointer to the root of the heap
* description: re-heapify the heap
* Return: void
*/

void heapify(heap_t *root)
{
    int temp;
    heap_t *temp_node = root;

    if (root->left != NULL && root->left->n > temp_node->n)
    {
        temp_node = root->left;
    }

    if (root->right != NULL && root->right->n > temp_node->n)
    {
        temp_node = root->right;
    }

    if (temp_node != root)
    {
        temp = root->n;
        root->n = temp_node->n;
        temp_node->n = temp;
        heapify(temp_node);
    }
}

/**
* helper_heap_extract - helper function for heap_extract
* @root: pointer to the root of the heap
* @height: the height of the tree
* @level: the level of the main node
* description: find the new root of the heap
* Return: new node
*/

heap_t *helper_heap_extract(heap_t *root, int height, int level)
{
    heap_t *temp;

    if (level >= height - 1)
    {
        if (root->right != NULL)
            return (root->right);
        else
            return (root->left);
    }
    temp = helper_heap_extract(root->left, height, level + 1);
    if (temp != NULL)
        return (temp);
    temp = helper_heap_extract(root->right, height, level + 1);
    return (temp);
}
