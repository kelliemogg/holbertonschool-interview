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

    if (root->left != NULL && root->left->n > root->right->n)
    {
        temp_node = root->left;
    }

    if (root->right != NULL && root->right->n > root->left->n)
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
        free(*root);
        *root = NULL;
        return (value);
    }

    height = binary_tree_height(temp, 1);
    temp = last_node(*root, height);
    (*root)->n = temp->n;
    if (temp->parent->right == temp)
        temp->parent->right = NULL;
    else
        temp->parent->left = NULL;
    heapify(*root);
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

heap_t *last_node(heap_t *root, int height)
{
    int left, right;
    heap_t *temp;

    if (height == 1)
        return (root);
    if (root->left != NULL)
    {
        left = binary_tree_height(root->left, 1);
    }
    if (root->right != NULL)
    {
        right = binary_tree_height(root->right, 1);
    }
    if (left > right)
    {
        temp = last_node(root->left, left);
    }
    else
    {
        temp = last_node(root->right, right);
    }
    return (temp);
}

