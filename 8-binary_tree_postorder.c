#include "binary_trees.h"

/**
 * binary_tree_postorder - print binary tree's nodes (inorder traversal method)
 * @tree: binary tree
 * @func: print function
 *
 * Return: void
 **/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || !func)
		return;
	if (tree->left)
		binary_tree_postorder(tree->left, func);
	if (tree->right)
		binary_tree_postorder(tree->right, func);
	func(tree->n);
}
