#include "binary_trees.h"

/**
 * sorted_array_to_avl - creates an AVL tree from a sorted array
 * @array: array of integers
 * @size: size of array
 * Return: pointer to the root node of the created AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    int middle = 0;
    avl_t *root = NULL;

    if (array == NULL || size == 0)
        return (NULL);
    middle = find_middle(0, size - 1);
    root = binary_tree_node(root, array[middle]);
    if (root == NULL)
        return (NULL);
    return (root);
}

/**
 * binary_tree_node - creates a binary tree node
 * 
 * @data: data to store in the node
 * Return: pointer to the created node
 */

avl_t *binary_tree_node(avl_t *root, int data)
{
    avl_t *parent = NULL, *current;
    avl_t *add_node = malloc(sizeof(avl_t));

    if (add_node == NULL)
        return (NULL);

    add_node->parent = NULL;
    add_node->left = NULL;
    add_node->right = NULL;
    add_node->n = data;
    if (parent == NULL)
        return (add_node);
    current = root;
    while (current != NULL)
    {
        parent = current;
        if (data < current->n)
            current = current->left;
        else
            current = current->right;
    }
    if (data < parent->n)
        parent->left = add_node;
    else
        parent->right = add_node;
    add_node->parent = parent;
    return (add_node);
}
/**
 * find_middle - finds the middle of an array
 * @start: start of the array
 * @end: end of the array
 * Return: the middle of the array
 */

int find_middle(int start, int end)
{
    int mid = 0;

    if (start > end)
        return (-1);
    if (start == end)
        return (start);
    mid = (start + end) / 2;
        return (mid);
}
