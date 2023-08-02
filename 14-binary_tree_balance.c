#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_balance - measure binary tree's balance
 * @tree: binary tree
 *
 * Return: tree's balance factor
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_balance, r_balance, b;

	if (tree == NULL)
		return (0);
	l_balance = (tree->left ? (1 + binary_tree_balance(tree->left)) : -1);
	r_balance = (tree->right ? (1 + binary_tree_balance(tree->right)) : -1);
	b = l_balance - r_balance;
	return (b > 1 ? 1 : b);
}
