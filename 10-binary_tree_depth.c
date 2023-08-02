#include "binary_trees.h"

/**
 * binary_tree_depth - measures a binary tree's node's depth
 * @tree: binary tree
 *
 * Return: node's depth
 **/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;
/*
*	const binary_tree_t *ptr = NULL;

	if (tree == NULL)
		return (0);
	ptr = tree;
	while (ptr->parent)
	{
		depth += 1;
		ptr = ptr->parent;
	}
*/
	if (tree == NULL)
		return (0);
	depth = (tree->parent ? 1 + binary_tree_depth(tree->parent) : 0);



	return (depth);
}
