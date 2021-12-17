#include "binary_trees.h"

/**
* heapify - re-heapify the heap
* @root: pointer to the root of the heap
* description: re-heapify the heap
* Return: void
*/

void heapify(heap_t *root)
{
    int temp;
    heap_t *temp_node;

    if (root->left && root->right == NULL)
        return;
    temp_node = root->left;
    if (root->right != NULL && root->right->n > temp_node->n)
    {
        temp_node = root->right;
    }

    if (temp_node->n > root->n)
    {
        temp = root->n;
        root->n = temp_node->n;
        temp_node->n = temp;
        heapify(temp_node);
    }
}

/**
* binary_tree_height - return the height of a binary tree
* @root: pointer to the root of the tree
* @height: the height of root node
* description: return the height of the tree
* Return: the height of the tree
*/

int binary_tree_height(heap_t *root)
{
    int left, right;
    if (!root)
        return (0);

    left = binary_tree_height(root->left);
    right = binary_tree_height(root->right);
    if (left > right)
        return (left + 1);
    else
        return (right + 1);
}

/**
* heap_extract - extract the root of a heap
* @root: double pointer to the root of the heap
* description: return the value stored in the root node
* then free the root node and re-heapify the heap
* Return: the value stored in the root node
*/
int heap_extract(heap_t **root)
{
    int value;
    heap_t *temp;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if (binary_tree_height(*root) == 1)
    {
        temp = *root;
        *root = NULL;
    }
    else
    {
        temp = last_node(*root);
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
* last_node - find the last node of a tree
* @root: pointer to the root of the tree
* @height: the height of the tree
* description: find the last node of a tree
* Return: pointer to the last node
*/

heap_t *last_node(heap_t *root)
{
    int left = 0, right = 0;

    if (root->left == NULL && root->right == NULL)
        return (root);
    if (root->left != NULL)
    {
        left = binary_tree_height(root->left);
    }
    if (root->right != NULL)
    {
        right = binary_tree_height(root->right);
    }
    if (right == left)
    {
        return (last_node(root->right));
    }
    return(last_node(root->left));
}