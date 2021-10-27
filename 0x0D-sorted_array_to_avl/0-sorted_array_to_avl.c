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
    
    printf("%d\n", middle);
    root = binary_tree_node(middle);
    if (root == NULL)
        return (NULL);

    root->left = sorted_array_to_avl(array + 1, size - 1);
    root->right = sorted_array_to_avl(array + 1, size - 1);

    return (root);
}

/**
 * binary_tree_node - creates a binary tree node
 * 
 * @data: data to store in the node
 * Return: pointer to the created node
 */

avl_t *binary_tree_node(int data)
{
    avl_t *node = malloc(sizeof(avl_t));

    if (node == NULL)
        return (NULL);

    node->n = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
