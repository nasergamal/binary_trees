#include "binary_trees.h"

/**
 * binary_tree_balance - measure binary tree's balance
 * @tree: binary tree
 *
 * Return: tree's balance factor
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_balance, r_balance;

	if (tree == NULL)
		return (0);
	l_balance = (tree->left ? (1 + binary_tree_balance(tree->left)) : 0);
	r_balance = (tree->right ? (1 + binary_tree_balance(tree->right)) : 0);
	return (l_balance - r_balance);
}
