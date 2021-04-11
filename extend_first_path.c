/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_first_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:42:48 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:48:32 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

int		go_with_flow(t_child *node, t_child *childs)
{
	t_child	*extended_nodes;
	t_child	*p2_child;

	extended_nodes = childs;
	p2_child = extended_nodes->room->childs;
	while (p2_child && p2_child->room != node->room)
		p2_child = p2_child->next;
	if (p2_child && p2_child->capacity == 0)
		return (1);
	return (0);
}

int		check_vis(t_child *path, t_room *room)
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

int		efp_helper1(t_queue *first_path, t_queue **extended_paths,
					t_queue **queue_list, t_child **group)
{
	t_child	*extended_node;
	t_child	*n_path;

	extended_node = first_path->last_node->room->childs;
	while (extended_node && (n_path = NULL) == NULL)
	{
		if (!(extended_node->room->visited) &&
			!(extended_node->room->in_paths))
		{
			if (extended_node->room == extended_node->room->farm->end)
			{
				*group = get_path_copy(first_path->node_list);
				return ((*queue_list = NULL) == NULL);
			}
			else
			{
				n_path = get_path_copy_plus(first_path->node_list,
						extended_node->room);
				*extended_paths = end_q(extended_paths, n_path,
						add_child(NULL, extended_node->room));
			}
		}
		extended_node = extended_node->next;
	}
	return (0);
}

t_queue	*extend_first_path(t_queue **queue_list, t_child **group,
		t_child **visited_list)
{
	t_queue	*first_path;
	t_queue	*extended_paths;

	first_path = NULL;
	extended_paths = NULL;
	if (queue_list)
	{
		first_path = *queue_list;
		if (first_path)
		{
			if (first_path->last_node)
			{
				if (!(first_path->last_node->room->visited))
				{
					add_child_head(visited_list, first_path->last_node->room);
					first_path->last_node->room->visited = 1;
				}
				if (efp_helper1(first_path, &extended_paths, queue_list, group))
					return (NULL);
			}
		}
	}
	return (extended_paths);
}
