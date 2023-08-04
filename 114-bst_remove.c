#include "binary_trees.h"
#include <stdio.h>
bst_t *min(bst_t *tree);
bst_t *search(const bst_t *tree, int value);
bst_t *successor(const bst_t *tree);
void unlinker(bst_t *tree);
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
	if (rmptr->left && rmptr->right)
	{
		ptr = successor(rmptr);
		if (ptr)
		{
			if (ptr->parent->left == ptr)
				ptr->parent->left = NULL;
			else
				ptr->parent->right = NULL;
			rmptr->n = ptr->n;
			free(ptr);
			return (root);
		}
	}
	unlinker(rmptr);
	return (root);
}
/**
 * unlinker - unlink all pointer to the node to be removed
 * @tree: binary tree
 *
 * Return: void
 */
void unlinker(bst_t *tree)
{
	if (!(tree->left) && !(tree->right))
	{
		if (tree->parent && tree->parent->left == tree)
			tree->parent->left = NULL;
		else if (tree->parent && tree->parent->right == tree)
			tree->parent->right = NULL;
		free(tree);
		return;
	}
	else
	{
		if (!(tree->right))
		{
			tree->left->parent = tree->parent;
			if (tree->parent->right == tree)
				tree->parent->right = tree->left;
			else if (tree->parent->left == tree)
				tree->parent->left = tree->left;
		}
		else if (!(tree->left))
		{
			tree->right->parent = tree->parent;
			if (tree->parent->right == tree)
				tree->parent->right = tree->right;
			else
				tree->parent->left = tree->right;
		}
		free(tree);
		return;
	}
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
	if (tree->right != NULL && tree->left != NULL)
	{
		tree = tree->right;
		while (tree->left != NULL)
			tree = tree->left;
		return ((bst_t *)tree);
	}
	return (NULL);
}
