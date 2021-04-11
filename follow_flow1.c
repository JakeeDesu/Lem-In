/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_flow1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:57:20 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:06:13 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

void	clear_flow(t_farm *farm)
{
	t_room	*room;
	t_child	*child;

	room = farm->rooms;
	while (room)
	{
		child = room->childs;
		while (child)
		{
			child->room->path_id = -1;
			child->room->in_paths = 0;
			child->room->in_flow = 0;
			child->capacity = 1;
			child->locked = 0;
			child = child->next;
		}
		room = room->next;
	}
}

void	push_flow_helper(t_child *childs, t_child *cross_node)
{
	childs->capacity = 1;
	cross_node->capacity = 1;
}

void	push_flow(t_child *child)
{
	t_child	*path;
	t_child	*childs;
	t_child	*cross_node;

	path = child;
	while (path->next)
	{
		childs = path->room->childs;
		while (childs && childs->room != path->next->room)
			childs = childs->next;
		if (childs)
		{
			cross_node = childs->room->childs;
			while (cross_node && cross_node->room != path->room)
				cross_node = cross_node->next;
			if (cross_node && cross_node->capacity == 0)
				push_flow_helper(childs, cross_node);
			else
				childs->capacity -= 1;
			childs->room->in_flow = 1;
		}
		path = path->next;
	}
}
