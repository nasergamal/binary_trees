#include "binary_trees.h"
#include <stdio.h>
/**
 * bst_search - search for a value in a binary search tree
 * @tree: binary search tree
 * @value: value in question
 *
 * Return: node if found or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->left && tree->n > value)
		return (bst_search(tree->left, value));
	if (tree->right && tree->n < value)
		return (bst_search(tree->right, value));
	return (NULL);
}
