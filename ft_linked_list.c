/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 06:27:15 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/30 06:27:15 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_create_list() creates new linked list with
 * given content (data) and returns it. 
 * 
 * @param data - The content of new linked list
 * @return t_list* - Created new linked list
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

t_list	*ft_create_list(int data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_list_size() counts number of nodes in the list
 * and returns it. If the list is empty or not given, return 0.
 * 
 * @param list - Parent List
 * @return unsigned int - Count of Nodes.
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

unsigned int	ft_list_size(t_list *list)
{
	unsigned int	count;

	count = 1;
	if (!list)
		return (0);
	while (list->next != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function gets last element from given list
 * and returns it.
 * 
 * @param list - Parent Linked List
 * @return t_list* - Last Node of List
 * 
 * @version 1.0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 */

t_list	*ft_list_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_add_list_front() inserts given new node
 * to the head (start) of given list 
 * 
 * @param list - Parent Linked List
 * @param head - The Node which will be inserted to the head of Parent List
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_add_list_front(t_list **list, t_list *head)
{
	if (!head)
		return ;
	head->next = *list;
	*list = head;
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_add_list_back() inserts given new node 
 * to the tail (end) of of given list 
 * 
 * @param list - Parent Linked List
 * @param tail - The Node which will be inserted to the tail of Parent List
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_add_list_back(t_list **list, t_list *tail)
{
	t_list	*tmp;

	if (!list)
		return ;
	if (!*list)
	{
		*list = tail;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tail;
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_print_list() prints data of all nodes in the list
 * Example: "5 8 2 6 2 1 3" - data field of nodes
 * 
 * @param list - The list which will be printed on the screen
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_print_list(t_list *list)
{
	if (!list)
	{
		printf("(NULL LIST)");
		return ;
	}
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_print_reverse_list() prints data of 
 * all nodes in the list by reverse order
 * Example: 
 * "5 8 2 6 2 1 3" -> "3 1 2 6 2 8 5"
 * 
 * @param list - The list which will be printed on the screen
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_print_reverse_list(t_list *list)
{
	if (!list)
		return ;
	ft_print_reverse_list(list->next);
	printf("%d ", list->data);
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_add_list_position() adds node to given
 * position in the Parent List
 * 
 * @param list - Parent Linked List
 * @param node - Added Node
 * @param position - Position of Node
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_add_list_position(t_list **list, t_list *node, int position)
{
	int		index;
	t_list	*tmp;
	t_list	*backup;

	index = 1;
	if (!list)
		return ;
	if (!node)
		return ;
	tmp = *list;
	while (tmp->next && index < position - 1)
	{
		index = index + 1;
		tmp = tmp->next;
	}
	if (index == position - 1)
	{
		backup = tmp->next;
		tmp->next = node;
		node->next = backup;
	}
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function reverse given linked list and returns it
 * to get more details, click link below:
 * https://www.geeksforgeeks.org/reverse-a-linked-list/?ref=leftbar-rightbar
 * 
 * @param list - The list which will be reversed
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_reverse_list(t_list **list)
{
	t_list	*current;
	t_list	*next;
	t_list	*previus;

	next = NULL;
	previus = NULL;
	current = *list;
	while (current)
	{
		next = current->next;
		current->next = previus;
		previus = current;
		current = next;
	}
	*list = previus;
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_list_delone() removes given node of list and
 * frees it's memory from heap memory.
 * 
 * @param list - The list which will be deleted
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_list_delone(t_list *list)
{
	if (!list)
		return ;
	free(list);
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_list_clear() removes all nodes of list and
 * frees it's memory from heap memory.
 * 
 * @param list - The list which will be deleted
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_list_clear(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

/**
 * @file ft_linked_list.c
 * @author Muhammed Karamuk (a_developer_2002@outlook.com)
 * @brief The function deletes node whose data field is equal to input key
 * 
 * @param list - The list whose node will be deleted
 * @param key - Input key
 * @return t_list* - Cleaned Linked List
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

t_list	*ft_delone_node_key(t_list **list, int key)
{
	t_list	*tmp;
	t_list	*previus;

	if (!list)
		return (NULL);
	tmp = *list;
	previus = NULL;
	if (tmp->data == key)
	{
		*list = tmp->next;
		free(tmp);
		return (*list);
	}
	while (tmp != NULL && tmp->data != key)
	{
		previus = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	previus->next = tmp->next;
	free(tmp);
	return (previus->next);
}

/**
 * @file ft_linked_list.c
 * @author Muhammed Karamuk (a_developer_2002@outlook.com)
 * @brief The function deletes all nodes whose data field is
 * equal to input key
 * 
 * @param list - The list whose node will be deleted
 * @param key - Input key
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_del_list_key(t_list **list, int key)
{
	t_list	*previus;
	t_list	*tmp;

	if (!list)
		return ;
	while (*list && (*list)->data == key)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	tmp = *list;
	while (1)
	{
		while (tmp != NULL && tmp->data != key)
		{
			previus = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return ;
		previus->next = tmp->next;
		free(tmp);
		tmp = previus->next;
	}
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_list_iter() iterates the list and 
 * applies the function ’func’ on the content of each node.
 * 
 * @param list - the address of a pointer to a node.
 * @param func - the address of the function used to iterate on the list.
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

void	ft_list_iter(t_list *list, void (*func)(int))
{
	if (!list || !func)
		return ;
	while (list)
	{
		(*func)(list->data);
		list = list->next;
	}
}

/**
 * @file ft_linked_list.c
 * @author Abdulaziz Abduvakhobov (abdulaziz.yosk@gmail.com)
 * @brief The function ft_list_map() iterates the list and 
 * applies the function 'func' on the content of each node.
 * Creates a new list resulting of the successive applications
 * of the function ’f’.
 * 
 * @param list - the address of a pointer to a node.
 * @param func - the address of the function used to iterate on the list.
 * @return t_list* - the new list
 * 
 * @version 1.0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 */

t_list	*ft_list_map(t_list *list, int(*func)(int))
{
	t_list	*node;
	t_list	*new_list;

	new_list = 0;
	while (list)
	{
		node = ft_create_list(func(list->data));
		if (!node)
		{
			ft_list_clear(&new_list);
			return (NULL);
		}
		ft_add_list_back(&new_list, node);
		list = list->next;
	}
	return (new_list);
}
