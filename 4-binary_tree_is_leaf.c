#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if binary tree's node is a leaf
 * @node: node to be checked
 *
 * Return: 0 if false or null, 1 if true
 **/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left || node->right)
		return (0);
	return (1);
}
