/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 04:26:28 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/30 04:26:28 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_queue.h"

/**
 * @file ft_queue.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The funciton ft_create_queue() creates new queue
 * with given capasity and returns it.
 * 
 * @param capasity - The length of created queue
 * @return t_queue* - Created queue
 * 
 * @version 1.0.2
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

t_queue	*ft_create_queue(int capasity)
{
	t_queue	*queue;

	if (capasity < 0)
		return (NULL);
	queue = (t_queue *) malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->capasity = capasity;
	queue->front = 0;
	queue->size = 0;
	queue->rear = queue->capasity - 1;
	queue->array = (int *) malloc(sizeof(int) * queue->capasity);
	return (queue);
}

/**
 * @file ft_queue.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_is_queue_empty() checks the queue and if it is empty
 * returns 1, otherwise 0.
 * 
 * @param queue - The queue
 * @return  1 or 0 - True or False
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022 
 */

int	ft_is_queue_empty(t_queue *queue)
{
	return (queue->size == 0);
}

/**
 * @file ft_queue.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_is_queue_full() checks the queue and if it is full
 * returns 1, otherwise 0.
 * 
 * @param queue - The queue
 * @return  1 or 0 - True or False
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022 
 */

int	ft_is_queue_full(t_queue *queue)
{
	return (queue->size == queue->capasity);
}

/**
 * @file ft_queue.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_enqueue() adds new item to the queue
 * 
 * @param queue - The queue which item will be added
 * @param item - The item (data) which will be added to queue
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022 
 */

void	ft_enqueue(t_queue *queue, int item)
{
	if (ft_is_queue_full(queue))
		return ;
	queue->rear = (queue->rear + 1) % queue->capasity;
	queue->size = queue->size + 1;
	queue->array[queue->rear] = item;
}

/**
 * @file ft_queue.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_dequeue() removes first element from the queue
 * 
 * @param queue - The queue
 * @return item - The removed first element
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022 
 */

int	ft_dequeue(t_queue *queue)
{
	int	item;

	if (ft_is_queue_empty(queue))
		return (INT_MIN);
	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capasity;
	queue->size = queue->size - 1;
	return (item);
}

/**
 * @file ft_queue.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_get_front() gets first element from queue
 * without removing it
 * 
 * @param queue - The queue
 * @return item - The first element of queue
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022 
 */

int	ft_get_front(t_queue *queue)
{
	if (ft_is_queue_empty(queue))
		return (INT_MIN);
	return (queue->array[queue->front]);
}

/**
 * @file ft_queue.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_get_rear gets last element from queue
 * without removing it
 * 
 * @param queue - The queue
 * @return item - The last element of queue
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022 
 */

int	ft_get_rear(t_queue *queue)
{
	if (ft_is_queue_empty(queue))
		return (INT_MIN);
	return (queue->array[queue->rear]);
}
