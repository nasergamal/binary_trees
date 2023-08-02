#include "binary_trees.h"

int t_height(const binary_tree_t *tree);
int t_size(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - determine if a binary tree's is perfect
 * @tree: binary tree
 *
 * Return: 0 or 1
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int tree_size, tree_height, ptree_nodes = 1, i;

	if (tree == NULL)
		return (0);
	tree_size = t_size(tree);
	tree_height = t_height(tree) + 1;
	for (i = 0; i < tree_height; i++)
		ptree_nodes *= 2;
	return (tree_size == (ptree_nodes - 1));
}

/**
 * t_height - measure tree's height
 * @tree: binary tree
 *
 * Return: height
 */
int t_height(const binary_tree_t *tree)
{
	int h_l, h_r;

	h_l = tree->left ? (1 + t_height(tree->left)) : 0;
	h_r = tree->right ? (1 + t_height(tree->right)) : 0;
	return (h_l > h_r ? h_l : h_r);
}
/**
 * t_size - count tree's nodes
 * @tree: binary tree
 *
 * Return: count
 */

int t_size(const binary_tree_t *tree)
{
	int s;

	s = 1;
	s += tree->left ? (t_size(tree->left)) : 0;
	s += tree->right ? (t_size(tree->right)) : 0;
	return (s);
}
