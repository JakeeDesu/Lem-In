/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:29:46 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:48:15 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_queue	*get_last_q(t_queue *queue_list)
{
	t_queue	*p_elem;

	p_elem = queue_list;
	if (p_elem)
	{
		while (p_elem->next)
		{
			p_elem = p_elem->next;
		}
	}
	return (p_elem);
}

t_queue	*new_q(t_child *node_list, t_child *last_node)
{
	t_queue *n_queue;

	n_queue = (t_queue*)mem_malloc(sizeof(t_queue), ALLOCATE);
	n_queue->crossed_paths = NULL;
	n_queue->node_list = node_list;
	n_queue->last_node = last_node;
	n_queue->end_q = n_queue;
	n_queue->prev = NULL;
	n_queue->next = NULL;
	return (n_queue);
}

t_queue	*head_q(t_queue **queue_list, t_child *node_list, t_child *last_node)
{
	t_queue	*n_elem;
	t_queue	*p_elem;

	n_elem = new_q(node_list, last_node);
	if (queue_list)
	{
		p_elem = *queue_list;
		if (p_elem)
		{
			*queue_list = n_elem;
			(*queue_list)->next = p_elem;
			p_elem->prev = (*queue_list);
		}
		else
			*queue_list = n_elem;
	}
	return (*queue_list);
}

t_queue	*end_q(t_queue **queue_list, t_child *node_list, t_child *last_node)
{
	t_queue	*n_elem;
	t_queue	*p_elem;

	n_elem = new_q(node_list, last_node);
	if (queue_list)
	{
		p_elem = *queue_list;
		if (p_elem)
		{
			p_elem = p_elem->end_q;
			n_elem->prev = p_elem;
			p_elem->next = n_elem;
			(*queue_list)->end_q = n_elem;
		}
		else
			*queue_list = n_elem;
	}
	return (*queue_list);
}

t_child	*delete_q(t_queue **queue_elem)
{
	t_child	*p_child;

	p_child = NULL;
	if (queue_elem)
	{
		if (*queue_elem)
		{
			p_child = (*queue_elem)->node_list;
			if ((*queue_elem)->prev && (*queue_elem)->next)
			{
				(*queue_elem)->prev->next = (*queue_elem)->next;
				(*queue_elem)->next->prev = (*queue_elem)->prev;
			}
			else if ((*queue_elem)->prev)
				(*queue_elem)->prev->next = (*queue_elem)->next;
			else if ((*queue_elem)->next)
				(*queue_elem)->next->prev = (*queue_elem)->prev;
		}
	}
	return (p_child);
}
