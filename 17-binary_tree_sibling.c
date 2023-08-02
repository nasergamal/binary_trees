#include "binary_trees.h"

/**
 * binary_tree_sibling - find node's sibling
 * @node: binary tree's node
 *
 * Return: sibling node
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *ptr = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	ptr = node->parent;
	if (!(ptr->left && ptr->right))
		return (NULL);
	if (ptr->left == node)
		return (ptr->right);
	return (ptr->left);
}
