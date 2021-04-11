/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:47:45 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:41:12 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_child	*launch_bfs(t_farm *farm)
{
	t_child	*path;
	t_queue	*queue;
	t_queue	*extended_paths;
	t_child	*visited_list;
	t_child *p_child;

	path = NULL;
	visited_list = NULL;
	queue = init_queue(farm->start);
	while (queue)
	{
		extended_paths = extend_first_path(&queue, &path, &visited_list);
		enqueue_paths(&queue, extended_paths);
	}
	p_child = visited_list;
	while (p_child)
	{
		p_child->room->visited = 0;
		p_child = p_child->next;
	}
	return (path);
}
