#include "binary_trees.h"
#include <stdio.h>
int check_function(const binary_tree_t *tree);
int minmax(binary_tree_t *tree, int method);
int binary_tree_h(const binary_tree_t *tree);
/**
 * binary_tree_is_avl - check if binary tree is avl
 * @tree: binary tree
 *
 * Return: 1 if true, 0 for false
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int b;

	if (tree == NULL)
		return (0);
	b = binary_tree_h(tree->left) - binary_tree_h(tree->right);
	if (b > 1 || b < 0)
		return (0);
	return (check_function(tree));
}

/**
 * check_function - check if avl
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

int binary_tree_h(const binary_tree_t *tree);
/**
 * binary_tree_balance - measure binary tree's balance
 * @tree: binary tree
 *
 * Return: tree's balance factor
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_h(tree->left) - binary_tree_h(tree->right));
}

/**
 * binary_tree_h - measure height
 * @tree: binary tree
 *
 * Return: height
 **/

int binary_tree_h(const binary_tree_t *tree)
{
	int l_balance, r_balance;

	if (tree == NULL)
		return (0);
	l_balance = (tree->left ? (1 + binary_tree_h(tree->left)) : 1);
	r_balance = (tree->right ? (1 + binary_tree_h(tree->right)) : 1);
	return (l_balance > r_balance ? l_balance : r_balance);
}
