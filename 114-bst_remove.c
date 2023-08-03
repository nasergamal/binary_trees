#include "binary_trees.h"
#include <stdio.h>
bst_t *min(bst_t *tree);
bst_t *search(const bst_t *tree, int value);
bst_t *successor(const bst_t *tree);

/**
 * bst_remove - remove binary search tree's node and add inorder successor
 * @root: tree root
 * @value: node's value
 *
 * Return: new root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *ptr = NULL, *rmptr;

	if (!root)
		return (NULL);
	rmptr = search(root, value);
	if (!rmptr)
		return (NULL);
	ptr = successor(rmptr);
	if (ptr->parent)
		ptr->parent->left = NULL;
	ptr->parent = rmptr->parent;
	if (ptr->parent)
	{
		if (ptr->parent->left == rmptr)
			ptr->parent->left = ptr;
		else
			ptr->parent->right = ptr;
	}
	else
		root = ptr;
	if (rmptr->left)
	{
		ptr->left = rmptr->left;
		ptr->left->parent = ptr;
	}
	if (rmptr->right)
	{
		ptr->right = rmptr->right;
		ptr->right->parent = ptr;
	}
	free(rmptr);
	return (root);
}

/**
 * search - search for a node
 * @tree: binary tree
 * @value: node's value
 *
 * Return: pointer to the node if found or NULL
 */
bst_t *search(const bst_t *tree, int value)
{
	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->left && tree->n > value)
		return (search(tree->left, value));
	if (tree->right && tree->n < value)
		return (search(tree->right, value));
	return (NULL);
}
/**
 * successor - search for a node inorder successor
 * @tree: binary tree
 *
 * Return: pointer to the node
 */
bst_t *successor(const bst_t *tree)
{
	bst_t *parent;

	if (tree->right != NULL)
		return (min(tree->right));
	if (tree->left != NULL)
		return (min(tree->left));
	parent = tree->parent;
	while (parent != NULL && tree == parent->right)
	{
		tree = parent;
		parent = parent->parent;
	}
	return (parent);
}
/**
 * min - auxillary function for successor
 * @tree: binary tree
 *
 * Return: pointer to the node
 */
bst_t *min(bst_t *tree)
{
	bst_t *current = tree;

	while (current->left != NULL)
		current = current->left;
	return (current);
}
