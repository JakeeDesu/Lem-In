/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:42:41 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:39:24 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_queue	*init_queue(t_room *start)
{
	t_child	*start_node;
	t_queue	*queue_list;

	start_node = NULL;
	queue_list = NULL;
	start_node = add_child(&start_node, start);
	queue_list = head_q(&queue_list, start_node, start_node);
	queue_list->crossed_paths = NULL;
	return (queue_list);
}
