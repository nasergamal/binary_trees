#include "binary_trees.h"

/**
 * binary_tree_height - measure binary tree's height
 * @tree: binary tree
 *
 * Return: tree's height
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (tree == NULL)
		return (0);
	l_height = (tree->left ? (1 + binary_tree_height(tree->left)) : 0);
	r_height = (tree->right ? (1 + binary_tree_height(tree->right)) : 0);
	return (l_height > r_height ? l_height : r_height);
}
