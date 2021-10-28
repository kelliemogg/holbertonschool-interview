#include "binary_trees.h"

/**
 * sorted_array_to_avl - creates an AVL tree from a sorted array
 * @array: array of integers
 * @size: size of array
 * Return: pointer to the root node of the created AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);
		

	return (binary_tree_node(NULL, 0, size - 1, array));
}

/**
 * binary_tree_node - creates a binary tree node
 * 
 * @data: data to store in the node
 * Return: pointer to the created node
 */

avl_t *binary_tree_node(avl_t *root, int first, int last, int *array)
{
	int mid;

	if (first > last)
		return (NULL);
	mid = (first + last) / 2;
	
	root = binary_tree_insert(root, array[mid]);
	if (root == NULL)
		return (NULL);
	root->left = binary_tree_node(root, first, mid - 1, array);
	root->right = binary_tree_node(root, mid + 1, last, array);
	return (root);
}

avl_t *binary_tree_insert(avl_t *root, int data)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);
	(new_node)->n = data;
	(new_node)->left = NULL;
	(new_node)->right = NULL;

	if (root == NULL)
	{
		new_node->parent = NULL;
		root = new_node;
	}
	else
	{
		if (data <= root->n)
		{
			new_node->parent = root;
			root->left = new_node;
		}
		else
		{
			new_node->parent = root;
			root->right = new_node;
		}
	}
	return (new_node);
}
