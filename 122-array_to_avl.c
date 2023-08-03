#include "binary_trees.h"

/**
 * array_to_avl - insert nodes created from an array into an avl binary tree
 * @array: new nodes values
 * @size: array size
 *
 * Return: tree
 **/
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		avl_insert(&tree, array[i]);
	}
	return (tree);
}
