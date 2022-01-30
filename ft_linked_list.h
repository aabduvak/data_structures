/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 06:27:50 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/30 06:27:50 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKED_LIST_H
# define FT_LINKED_LIST_H

# include <stdlib.h>
# include <stdio.h> 

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list			*ft_create_list(int data);
t_list			*ft_delone_node_key(t_list **list, int key);
t_list			*ft_list_last(t_list *list);
t_list			*ft_list_map(t_list *list, int(*func)(int));

unsigned int	ft_list_size(t_list *list);

void			ft_add_list_front(t_list **list, t_list *head);
void			ft_add_list_back(t_list **list, t_list *tail);
void			ft_print_list(t_list *list);
void			ft_print_reverse_list(t_list *list);
void			ft_add_list_position(t_list **list, t_list *node, int position);
void			ft_reverse_list(t_list **list);
void			ft_list_delone(t_list *list);
void			ft_list_clear(t_list **list);
void			ft_del_list_key(t_list **list, int key);
void			ft_list_iter(t_list *list, void (*func)(int));

#endif