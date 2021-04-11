/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:14:18 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:48:35 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_queue	*add_to_end(t_queue **queue_list, t_queue *queue_list2)
{
	t_queue	*p1_queue;

	if (queue_list)
	{
		if (!(*queue_list))
			*queue_list = queue_list2;
		else
		{
			p1_queue = (*queue_list)->end_q;
			p1_queue->next = queue_list2;
			if (queue_list2)
			{
				queue_list2->prev = p1_queue;
				(*queue_list)->end_q = queue_list2->end_q;
			}
		}
		return (*queue_list);
	}
	return (NULL);
}

void	enqueue_paths(t_queue **queue_list, t_queue *extended_paths)
{
	t_queue	*p_queue;

	if (queue_list)
	{
		if (*queue_list)
		{
			p_queue = (*queue_list)->next;
			if (p_queue)
				p_queue->end_q = (*queue_list)->end_q;
		}
		else
			p_queue = NULL;
		p_queue = add_to_end(&p_queue, extended_paths);
		if ((*queue_list) && (*queue_list)->crossed_paths)
			while (extended_paths)
			{
				extended_paths->crossed_paths =
					get_path_copy((*queue_list)->crossed_paths);
				extended_paths = extended_paths->next;
			}
		delete_q(queue_list);
		*queue_list = p_queue;
	}
}
