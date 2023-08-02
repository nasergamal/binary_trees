#include "binary_trees.h"

/**
 * binary_tree_leaves - count binary tree's leaves
 * @tree: binary tree
 *
 * Return: tree's leaves
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int tree_leaves = 0;

	if (tree == NULL)
		return (0);
	if (!tree->left && !tree->right)
		tree_leaves += 1;
	tree_leaves += (tree->left ? (binary_tree_leaves(tree->left)) : 0);
	tree_leaves += (tree->right ? (binary_tree_leaves(tree->right)) : 0);
	return (tree_leaves);
}
