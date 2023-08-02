#include "binary_trees.h"

/**
 * binary_tree_nodes - count binary tree's nodes with at least 1 child
 * @tree: binary tree
 *
 * Return: tree's nodes
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int tree_nodes = 0;

	if (tree == NULL)
		return (0);
	if (tree->left || tree->right)
		tree_nodes += 1;
	tree_nodes += (tree->left ? (binary_tree_nodes(tree->left)) : 0);
	tree_nodes += (tree->right ? (binary_tree_nodes(tree->right)) : 0);
	return (tree_nodes);
}
