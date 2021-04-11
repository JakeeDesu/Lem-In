/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:43:44 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:43:09 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

void	init_room_ants(t_child *child)
{
	t_child	*p_child;

	p_child = child;
	while (p_child)
	{
		if (p_child->room)
			p_child->room->ant_nb = 0;
		p_child = p_child->next;
	}
}

void	init_paths(t_paths *paths)
{
	t_paths	*p_paths;

	p_paths = paths;
	while (p_paths)
	{
		p_paths->in_q = 0;
		init_room_ants(p_paths->path);
		p_paths->length = path_length(p_paths->path);
		p_paths->length_v = p_paths->length;
		p_paths = p_paths->next;
	}
}

t_paths	*get_shortest_path(t_paths *paths)
{
	t_paths	*p_paths;
	t_paths *min_paths;

	p_paths = paths;
	min_paths = p_paths;
	p_paths = p_paths->next;
	while (p_paths)
	{
		if (p_paths->length_v < min_paths->length_v)
			min_paths = p_paths;
		p_paths = p_paths->next;
	}
	return (min_paths);
}

void	prepare_q(t_paths *paths, int ant_nb)
{
	int		ant_wallet;
	t_paths	*short_paths;

	ant_wallet = ant_nb;
	init_paths(paths);
	while (ant_wallet > 0)
	{
		short_paths = get_shortest_path(paths);
		(short_paths->in_q)++;
		(short_paths->length_v)++;
		ant_wallet--;
	}
}
