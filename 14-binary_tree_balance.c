#include "binary_trees.h"
#include <stdio.h>
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
