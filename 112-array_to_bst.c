#include "binary_trees.h"

/**
 * array_to_bst - insert nodes created from an array into a binary search tree
 * @array: new nodes values
 * @size: array size
 *
 * Return: tree
 **/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}
	return (tree);
}
