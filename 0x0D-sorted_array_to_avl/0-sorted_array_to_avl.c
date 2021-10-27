#include "binary_trees.h"

/**
 * sorted_array_to_avl - creates an AVL tree from a sorted array
 * @array: array of integers
 * @size: size of array
 * Return: pointer to the root node of the created AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;

    if (array == NULL || size == 0)
        return (NULL);
    
    root = binary_tree_node(NULL, array[0]);
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

avl_t *binary_tree_node(binary_tree_t *parent, int data)
{
    avl_t *node = malloc(sizeof(avl_t));

    if (node == NULL)
        return (NULL);

    node->n = data;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
