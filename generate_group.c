/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:30:55 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:42:03 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_paths	*generate_group(t_farm *farm, t_child *base_path)
{
	t_paths	*group;
	t_child	*path;

	path = NULL;
	group = NULL;
	if (base_path)
		add_path(&group, base_path, 1);
	while ((path = launch_bfs(farm)))
	{
		add_path(&group, path, 1);
	}
	clear_in_paths(group);
	return (group);
}
