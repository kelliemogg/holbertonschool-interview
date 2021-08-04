#include "binary_trees.h"
#include <stdlib.h>

/*
* binary_tree_node - creates a node
* description: creates a binary tree node
* @parent: ptr to the parent node
* @value: value for new node
* return: ptr to new node or NULL for fail
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *newb;
    newb = malloc(sizeof(binary_tree_t));

    if (!value)
        return NULL;

    /* setting value to the new node */
    newb->n = value;
    /* setting *parent as parent to new node */
    newb->parent = parent;
    newb->left = NULL;
    newb->right = NULL;
    return (newb);
}