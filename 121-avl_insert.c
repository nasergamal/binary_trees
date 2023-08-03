#include "binary_trees.h"
#include <stdio.h>
avl_t *insert(avl_t **tree, int value, avl_t **new_node, avl_t *ancestor);
/**
 * avl_insert - create and insert new node into a binary search tree
 * @tree: binary search tree
 * @value: new node value
 *
 * Return: new node
 **/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	insert(tree, value, &new_node, *tree);
	if (new_node == NULL)
		return (NULL);
	return (new_node);
}
/**
 * insert - complementary recursive function for node insertion and balancing
 * @tree: binary tree
 * @value: new node's value
 * @new_node: pointer to new node
 * @parent: new node's parent node
 *
 * Return: tree
 */
avl_t *insert(avl_t **tree, int value, avl_t **new_node, avl_t *parent)
{
	int b;

	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		return (*new_node);
	}
	else if ((*tree)->n > value)
	{
		(*tree)->left = insert(&(*tree)->left, value, new_node, *tree);
		if (!((*tree)->left))
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = insert(&(*tree)->right, value, new_node, *tree);
		if (!((*tree)->right))
			return (NULL);
	}
	b = binary_tree_balance(*tree);

	if (b < -1 && ((*tree)->right->n > value))
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left((*tree));
	}
	else if (b < -1 && ((*tree)->right->n < value))
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (b > 1 && ((*tree)->left->n > value))
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b > 1 && ((*tree)->left->n < value))
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right((*tree));
	}
	return (*tree);
}
