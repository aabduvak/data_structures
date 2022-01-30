/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 04:30:06 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/30 04:30:06 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stdlib.h>

typedef struct s_queue
{
	int		capasity;
	int		size;
	int		front;
	int		rear;
	int		*array;
}	t_queue;

#endif