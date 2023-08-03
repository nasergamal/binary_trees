#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotate the tree to the right
 * @tree: binary tree
 *
 * Return: ptr to new root
 **/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *ptr = NULL;

	if (tree == NULL || !tree->left)
		return (NULL);
	ptr = tree->left;
	ptr->parent = tree->parent;
	tree->parent = ptr;
	tree->left = ptr->right;
	if (tree->left)
		tree->left->parent = tree;
	if (ptr->parent)
	{
		if (ptr->parent->left == tree)
			ptr->parent->left = ptr;
		else
			ptr->parent->right = ptr;
	}
	ptr->right = tree;
	return (ptr);
}
