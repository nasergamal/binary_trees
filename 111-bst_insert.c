#include "binary_trees.h"

/**
 * bst_insert - create and insert new node into a binary search tree
 * @tree: binary search tree
 * @value: new node value
 *
 * Return: new node
 **/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *ptr;

	if (!tree)
		return (NULL);
	ptr = *tree;
	if (!ptr)
	{
		new_node = binary_tree_node(ptr, value);
		*tree = new_node;
		return (new_node);
	}
	if (ptr->n > value)
	{
		if (ptr->left)
			return (bst_insert(&ptr->left, value));
		new_node = binary_tree_node(ptr, value);
		if (!ptr)
			return (NULL);
		ptr->left = new_node;
		return (new_node);
	}
	if (ptr->n < value)
	{
		if (ptr->right)
			return (bst_insert(&ptr->right, value));
		new_node = binary_tree_node(ptr, value);
		if (!ptr)
			return (NULL);
		ptr->right = new_node;
		return (new_node);
	}
	return (NULL);
}
