#include "binary_trees.h"
/**
 * binary_tree_rotate_left - rotate the tree to the left
 * @tree: binary tree
 *
 * Return: ptr to new root
 **/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *ptr = NULL;

	if (tree == NULL || !tree->right)
		return (NULL);
	ptr = tree->right;
	tree->right = ptr->left;
	ptr->left = tree;
	ptr->parent = tree->parent;
	tree->parent = ptr;
	if (tree->right)
		tree->right->parent = tree;
	if (ptr->parent)
	{
		if (ptr->parent->left == tree)
			ptr->parent->left = ptr;
		else
			ptr->parent->right = ptr;
	}
	return (ptr);
}
