/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_first_path2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:33:05 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:04:30 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

int		visited_check(t_child *path, t_room *room)
{
	t_child *p_child;

	p_child = path;
	while (p_child)
	{
		if (p_child->room == room)
			return (0);
		p_child = p_child->next;
	}
	return (1);
}

int		efp2_helper1(t_child **extended_node, t_queue *first_path,
		t_queue **extended_paths)
{
	t_child *n_path;

	n_path = NULL;
	if (!(*extended_node = go_with_flow2(first_path->last_node,
			*extended_node)))
		return (1);
	add_child_head(&(first_path->crossed_paths), (*extended_node)->room);
	if ((*extended_node)->capacity && visited_check(first_path->node_list,
			(*extended_node)->room))
	{
		n_path = get_path_copy_plus(first_path->node_list,
			(*extended_node)->room);
		*extended_paths = end_q(extended_paths, n_path,
			add_child(NULL, (*extended_node)->room));
	}
	return (0);
}

void	efp2_helper3(t_queue *first_path,
	t_queue **extended_paths, t_child *extended_node)
{
	t_child	*n_path;

	n_path = NULL;
	n_path = get_path_copy_plus(first_path->node_list,
		extended_node->room);
	*extended_paths = end_q(extended_paths, n_path, add_child(NULL,
		extended_node->room));
}

int		efp2_helper2(t_queue *first_path, t_queue **queue_list, t_child **group,
				t_queue **extended_paths)
{
	t_child	*extended_node;

	extended_node = first_path->last_node->room->childs;
	while (extended_node)
	{
		if (extended_node->capacity &&
			visited_check(first_path->node_list, extended_node->room))
		{
			if (extended_node->room == extended_node->room->farm->end &&
				first_path->crossed_paths)
			{
				*group = get_path_copy(first_path->node_list);
				return ((*queue_list = NULL) == NULL);
			}
			else
				efp2_helper3(first_path, extended_paths, extended_node);
		}
		extended_node = extended_node->next;
	}
	return (0);
}

t_queue	*extend_first_path2(t_queue **queue_list, t_child **group)
{
	t_queue	*first_path;
	t_queue	*extended_paths;
	t_child	*extended_node;

	first_path = NULL;
	extended_paths = NULL;
	extended_node = NULL;
	if (queue_list)
	{
		first_path = *queue_list;
		if (first_path && first_path->last_node)
		{
			extended_node = first_path->last_node->room->childs;
			if (first_path->last_node->room->in_flow && check_if_crossed(
				first_path, first_path->last_node->room->path_id) == 0)
			{
				if (efp2_helper1(&extended_node, first_path, &extended_paths))
					return (NULL);
			}
			else if (efp2_helper2(
					first_path, queue_list, group, &extended_paths))
				return (NULL);
		}
	}
	return (extended_paths);
}
