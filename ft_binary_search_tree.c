/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:22:15 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/30 18:22:15 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binary_search_tree.h"

/**
 * @file ft_binary_search_tree.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_bstree_create() creates new bstree node with
 * given content (data) and returns it. 
 * 
 * @param data - The content of new node
 * @param tree - The address of a pointer to a node.
 * @return t_bstree* - New Node of Binary Search Tree
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

t_bstree	*ft_bstree_create(t_bstree *tree, int data)
{
	t_bstree *root;

	if (!tree)
	{
		root = (t_bstree *) malloc(sizeof(t_bstree));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return (root);
	}
	if (tree->data < data)
	{
		tree->right = ft_bstree_create(tree->right, data);
		return (tree);
	}
	tree->left = ft_bstree_create(tree->left, data);
	return (tree);
}

/**
 * @file ft_binary_search_tree.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_bstree_search() tries to find given
 * value from the tree if finds, will return 1. Otherwise
 * return -1.
 * 
 * @param tree - The address of a pointer to a node.
 * @param value - Searching argument
 * @return t_bstree* - New Node of Binary Search Tree
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

int	ft_bstree_search(t_bstree *tree, int value)
{
	if (!tree)
		return (-1);
	if (tree->data == value)
		return (1);
	if (ft_bstree_search(tree->left, value))
		return (1);
	if (ft_bstree_search(tree->right, value))
		return (1);
	return (-1);
}

/**
 * @file ft_binary_search_tree.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_bstree_max() gets max value from the tree.
 * 
 * @param tree - The address of a pointer to a node.
 * @return int - Max value of Tree.
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

int	ft_bstree_max(t_bstree *tree)
{
	while (tree->right)
		tree = tree->right;
	return (tree->data);
}

/**
 * @file ft_binary_search_tree.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_bstree_min() gets min value from the tree.
 * 
 * @param tree - The address of a pointer to a node.
 * @return int - Min value of Tree.
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

int	ft_bstree_min(t_bstree *tree)
{
	while (tree->left)
		tree = tree->left;
	return (tree->data);
}

/**
 * @file ft_binary_search_tree.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_bstree_traverse() prints all data from the tree.
 * 
 * @param tree - The address of a pointer to a node.
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_bstree_traverse(t_bstree *tree)
{
	if (!tree)
		return ;
	ft_bstree_traverse(tree->left);
	printf("%d ", tree->data);
	ft_bstree_traverse(tree->right);	
}

/**
 * @file ft_binary_search_tree.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_bstree_delnode() removes node if the
 * data is matches with parameter. Otherwise returns NULL
 * 
 * @param tree - The address of a pointer to a node.
 * @param value - Content of Node, which will be deleted from the Tree.
 * @return tree - New cleaned tree
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

t_bstree	*ft_bstree_delnode(t_bstree *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->data == value)
	{
		if (!tree->left && !tree->right)
			return (NULL);
		if (tree->right)
		{
			tree->data = ft_bstree_min(tree->right);
			tree->right = ft_bstree_delnode(tree->right, ft_bstree_min(tree->right));
			return (tree);
		}
		tree->data = ft_bstree_max(tree->left);
		tree->left = ft_bstree_delnode(tree->left, ft_bstree_max(tree->left));
		return (tree);
	}
	if (tree->data < value)
	{
		tree->right = ft_bstree_delnode(tree->right, value);
		return (tree);
	}
	tree->left = ft_bstree_delnode(tree->left, value);
	return (tree);
}
