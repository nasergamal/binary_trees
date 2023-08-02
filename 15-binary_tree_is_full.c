#include "binary_trees.h"

/**
 * binary_tree_is_full - determine if a binary tree's is full
 * @tree: binary tree
 *
 * Return: 0 or 1
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if ((tree->left && !tree->right) || (!tree->left && tree->right) ||
	    (tree->left && binary_tree_is_full(tree->left) == 0) ||
	    (tree->right && binary_tree_is_full(tree->right) == 0))
		return (0);
	return (1);
}
