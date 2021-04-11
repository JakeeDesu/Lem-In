/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:57:20 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:05:43 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

void	push_flow_to_paths(t_paths *paths)
{
	t_paths	*p_paths;

	p_paths = paths;
	while (p_paths)
	{
		push_flow(p_paths->path);
		p_paths = p_paths->next;
	}
}

void	follow_flow_helper(t_child *all_paths, t_child **path, t_farm *farm)
{
	t_child	*pointer;

	pointer = all_paths;
	while (pointer)
	{
		if (pointer->room != farm->end)
			add_child_end(path, pointer->room);
		pointer = pointer->room->childs;
		while (pointer && pointer->capacity != 0)
			pointer = pointer->next;
	}
}

t_paths	*follow_flow(t_farm *farm)
{
	t_child *all_paths;
	t_child	*path;
	t_paths	*group;

	all_paths = farm->start->childs;
	group = NULL;
	while (all_paths)
	{
		if (all_paths->capacity == 0)
		{
			path = NULL;
			add_child_end(&path, farm->start);
			follow_flow_helper(all_paths, &path, farm);
			if (path)
				add_path(&group, path, 0);
		}
		all_paths = all_paths->next;
	}
	return (group);
}
