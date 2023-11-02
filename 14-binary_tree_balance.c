#include "binary_trees.h"
/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: 0 if tree is NULL, otherwise return height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
/**
 * binary_tree_balance - a function that measures the balance factor
 * of a binary tree
 * @tree: a pointer to the root node of the tree to measure the
 * balance factor
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
