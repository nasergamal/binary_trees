#include "binary_trees.h"
int t_size(const binary_tree_t *tree);
int complete(const binary_tree_t *tree, int size, int idx);
/**
 * binary_tree_is_complete - determine if a binary tree's is perfect
 * @tree: binary tree
 *
 * Return: 0 or 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int tree_size;

	if (tree == NULL)
		return (0);
	tree_size = t_size(tree);
	return (complete(tree, tree_size, 0));
}

/**
 * complete - complement is complete function
 * @tree: binary tree
 * @size: tree size
 * @idx: current idx
 *
 * Return: 0 or 1
 */
int complete(const binary_tree_t *tree, int size, int idx)
{
	if (tree == NULL)
		return (1);
	if (idx >= size)
		return (0);

	return (complete(tree->left, size, (idx * 2) + 1)
		&& complete(tree->right, size, (idx * 2) + 2));
}


/**
 * t_size - count tree's nodes
 * @tree: binary tree
 *
 * Return: count
 */

int t_size(const binary_tree_t *tree)
{
	int s;

	s = 1;
	s += tree->left ? (t_size(tree->left)) : 0;
	s += tree->right ? (t_size(tree->right)) : 0;
	return (s);
}
