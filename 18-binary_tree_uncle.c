#include "binary_trees.h"

/**
 * binary_tree_uncle - find node's sibling
 * @node: binary tree's node
 *
 * Return: uncle node
 **/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *ptr = NULL, *ptr2 = NULL;

	if (node == NULL || node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	ptr = node->parent->parent;
	ptr2 = node->parent;
	if (!(ptr->left && ptr->right))
		return (NULL);
	if (ptr->left == ptr2)
		return (ptr->right);
	return (ptr->left);
}
