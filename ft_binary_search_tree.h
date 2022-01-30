/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search_tree.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:22:19 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/30 18:22:19 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_SEARCH_TREE_H
# define FT_BINARY_SEARCH_TREE_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_bstree 
{
	int				data;
	struct s_bstree	*left;
	struct s_bstree	*right;
}					t_bstree;

t_bstree	*ft_bstree_create(t_bstree *tree, int data);
t_bstree	*ft_bstree_delnode(t_bstree *tree, int value);

int			ft_bstree_search(t_bstree *tree, int value);
int			ft_bstree_max(t_bstree *tree);
int			ft_bstree_min(t_bstree *tree);

void		ft_bstree_traverse(t_bstree *tree);

#endif