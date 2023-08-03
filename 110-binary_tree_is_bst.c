#include "binary_trees.h"
#include <stdio.h>
int check_function(const binary_tree_t *tree);
int minmax(binary_tree_t *tree, int method);
/**
 * binary_tree_is_bst - check if binary tree is bst
 * @tree: binary tree
 *
 * Return: 1 if true, 0 for false
 **/
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	return (check_function(tree));
}

/**
 * check_function - check if bst
 * @tree: binary tree
 *
 * Return: 1 (success) or 0 (failure)
 **/
int check_function(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if ((tree->left && (minmax(tree->left, 0) > tree->n)) ||
	   (tree->right && (minmax(tree->right, 1) < tree->n)))
		return (0);

	if (!(check_function(tree->left))
		|| !(check_function(tree->right)))
		return (0);
	return (1);
}

/**
 * minmax - get the min or max value for comparison
 * @tree: binary tree
 * @method: 1 for min 0 for max
 *
 * Return: min or max value
 */
int minmax(binary_tree_t *tree, int method)
{
	int low, high, value;

	if (!tree)
	{
		if (method == 1)
			return (9999999);
		return (0);
	}

	low = minmax(tree->left, method);
	high = minmax(tree->right, method);
	if ((low < high) == method)
		value = low;
	else
		value = high;
	if ((tree->n < value) == method)
		value = tree->n;
	return (value);
}
