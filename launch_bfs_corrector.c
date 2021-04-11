/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bfs_corrector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:48:51 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:40:52 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_child	*launch_maximizer(t_farm *farm)
{
	t_child	*path;
	t_queue	*queue;
	t_queue	*extended_paths;
	int		time;

	time = 0;
	path = NULL;
	queue = init_queue(farm->start);
	while (queue)
	{
		time++;
		if (time > 12000)
			return (NULL);
		extended_paths = extend_first_path2(&queue, &path);
		enqueue_paths(&queue, extended_paths);
	}
	return (path);
}
