#include "binary_trees.h"

/**
 * binary_trees_ancestor - find nodes' common ancestor
 * @first: first node
 * @second: second node
 *
 * Return: ancestor node
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ptr = NULL, *ptr2 = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	ptr = (binary_tree_t *)first;
	ptr2 = (binary_tree_t *)second;
	while (ptr2 != NULL)
	{
		ptr = (binary_tree_t *)first;
		while (ptr != NULL)
		{
			if (ptr == ptr2)
				return (ptr);
			ptr = ptr->parent;
		}
		ptr2 = ptr2->parent;
	}
	return (NULL);
}
