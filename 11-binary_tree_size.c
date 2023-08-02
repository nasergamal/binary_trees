#include "binary_trees.h"

/**
 * binary_tree_size - measure binary tree's size
 * @tree: binary tree
 *
 * Return: tree's size
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{
	int tree_size = 0;

	if (tree == NULL)
		return (0);
	tree_size += 1;
	tree_size += (tree->left ? (binary_tree_size(tree->left)) : 0);
	tree_size += (tree->right ? (binary_tree_size(tree->right)) : 0);
	return (tree_size);
}
