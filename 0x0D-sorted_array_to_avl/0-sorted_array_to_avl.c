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

    if (array == NULL)
        return (NULL);
    root = binary_tree_node(array[0]);
    if (root == NULL)
        return (NULL);
    if (size > 1)
        root->left = sorted_array_to_avl(array + 1, size - 1);
    if (size > 1)
        root->right = sorted_array_to_avl(array + 1, size - 1);
    return (root);
}