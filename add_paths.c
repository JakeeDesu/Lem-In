/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:11:45 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:48:39 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_paths	*add_paths(t_child *n_path, int in_paths, int path_id)
{
	t_paths	*n_paths;
	t_child	*childs;

	n_paths = (t_paths*)mem_malloc(sizeof(t_paths), ALLOCATE);
	childs = n_path;
	n_paths->in_queue = 0;
	n_paths->length = 0;
	n_paths->path_id = path_id;
	while (childs)
	{
		(n_paths->length)++;
		if (childs->room != childs->room->farm->start)
		{
			childs->room->path_id = path_id;
			childs->room->in_paths = in_paths;
		}
		childs = childs->next;
	}
	n_paths->path = n_path;
	n_paths->next = NULL;
	return (n_paths);
}

void	add_path(t_paths **paths_holder, t_child *n_path, int in_paths)
{
	t_paths	*p_paths;

	if (!(*paths_holder))
	{
		*paths_holder = add_paths(n_path, in_paths, 0);
		(*paths_holder)->path_nb = 1;
	}
	else
	{
		(*paths_holder)->path_nb += 1;
		p_paths = *paths_holder;
		while (p_paths->next)
			p_paths = p_paths->next;
		p_paths->next = add_paths(n_path, in_paths, p_paths->path_id + 1);
	}
}

void	clear_in_paths(t_paths *paths)
{
	t_paths *p_path;
	t_child	*p_child;

	p_path = paths;
	while (p_path)
	{
		p_child = p_path->path;
		while (p_child)
		{
			p_child->room->in_paths = 0;
			p_child = p_child->next;
		}
		p_path = p_path->next;
	}
}
