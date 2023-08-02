#include "binary_trees.h"

/**
 * binary_tree_inorder - print binary tree's nodes (inorder traversal method)
 * @tree: binary tree
 * @func: print function
 *
 * Return: void
 **/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || !func)
		return;
	if (tree->left)
		binary_tree_inorder(tree->left, func);
	func(tree->n);
	if (tree->right)
		binary_tree_inorder(tree->right, func);
}
