/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_first_path3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:33:05 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:05:10 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_child	*go_with_flow2(t_child *node, t_child *childs)
{
	t_child	*extended_nodes;
	t_child	*p2_child;

	extended_nodes = childs;
	while (extended_nodes)
	{
		p2_child = extended_nodes->room->childs;
		while (p2_child && p2_child->room != node->room)
			p2_child = p2_child->next;
		if (p2_child && p2_child->capacity == 0)
		{
			return (extended_nodes);
		}
		extended_nodes = extended_nodes->next;
	}
	return (NULL);
}

int		check_if_crossed(t_queue *queue, int path_id)
{
	t_child	*crossed_paths;

	crossed_paths = queue->crossed_paths;
	while (crossed_paths)
	{
		if (crossed_paths->room->path_id == path_id)
			return (1);
		crossed_paths = crossed_paths->next;
	}
	return (0);
}
