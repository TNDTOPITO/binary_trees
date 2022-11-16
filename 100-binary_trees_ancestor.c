#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *dad;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, dad = second->parent;
	if (first == dad || !mom || (!mom->parent && dad))
		return (binary_trees_ancestor(first, dad));
	else if (mom == second || !dad || (!dad->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, dad));
}
