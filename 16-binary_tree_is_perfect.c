#include "binary_trees.h"
/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a ponter to the root node of the tree to measure the height
 * Return: 0 if tree in NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree)
	{
		left_height = 0;
		right_height = 0;

		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * binary_tree_is_perfect_recursive - check if a binary tree
 * is perfect(recursive)
 * @tree: a pointer to the current node being checked
 * @level: the level of the current node
 * @height: the height of the tree
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree, size_t level,
		size_t height)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (level == height);
	}

	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}

	return (binary_tree_is_perfect_recursive(tree->left, level + 1, height)
			&& binary_tree_is_perfect_recursive(tree->right, level
				+ 1, height));
}
/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
	{
		return (0);
	}

	height = binary_tree_height(tree);

	return (binary_tree_is_perfect_recursive(tree, 0, height));
}
