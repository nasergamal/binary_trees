#include "binary_trees.h"

void levelorder(const binary_tree_t *tree, void (*func)(int));
/**
 * binary_tree_levelorder - print binary tree's nodes (levelorder method)
 * @tree: binary tree
 * @func: print function
 *
 * Return: void
 **/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || !func)
		return;
	func(tree->n);
	levelorder(tree, func);
}

/**
 * levelorder - levelorder traversal method
 * @tree: binary tree
 * @func: print function
 *
 * Return: void
 **/
void levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree->left)
	{
		func(tree->left->n);
		if (tree->right)
			func(tree->right->n);
		levelorder(tree->left, func);
	}
	else
	{
		binary_tree_levelorder(tree->right, func);
		return;
	}
	if (tree->right)
		levelorder(tree->right, func);
}
