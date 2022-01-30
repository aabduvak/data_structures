/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:32:58 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/30 03:32:58 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int			top;
	int			capacity;
	int			*array;
}				t_stack;

t_stack	*ft_create_stack(int capacity);

int		ft_is_stack_full(t_stack *Stack);
int		ft_is_stack_empty(t_stack *Stack);
int		ft_pop_stack(t_stack *Stack);

void	ft_push_stack(t_stack *Stack, int item);

#endif