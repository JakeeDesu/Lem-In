/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_right_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:59:27 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:40:32 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_paths	*simple_solver(t_farm *farm)
{
	t_paths	*selected;
	t_paths	*base_paths;
	t_paths	*new_paths;
	int		score;
	int		best_score;

	base_paths = NULL;
	base_paths = generate_group(farm, NULL);
	selected = base_paths;
	best_score = put_instructions2(selected, farm->ant_nb, 0);
	while (base_paths)
	{
		new_paths = NULL;
		new_paths = generate_group(farm, base_paths->path);
		score = put_instructions2(new_paths, farm->ant_nb, 0);
		if (score < best_score)
		{
			best_score = score;
			selected = new_paths;
		}
		base_paths = base_paths->next;
	}
	return (selected);
}

void	ultimate_solver_helper(int max, int *best_score,
			t_farm *farm, t_paths **selected)
{
	int		paths_nb;
	int		score;
	t_paths	*new_paths;
	t_child	*path;
	int		is_big;

	paths_nb = 0;
	is_big = 0;
	while ((paths_nb < max) && (path = launch_maximizer(farm)))
	{
		is_big++;
		push_flow(path);
		new_paths = follow_flow(farm);
		score = put_instructions2(new_paths, farm->ant_nb, 0);
		if (score < *best_score)
		{
			*best_score = score;
			*selected = new_paths;
		}
		paths_nb = new_paths->path_nb;
	}
	if (is_big == 0)
		*selected = generate_group(farm, NULL);
}

t_paths	*ultimate_solver(t_farm *farm)
{
	t_paths	*selected;
	t_paths	*new_paths;
	int		score;
	int		best_score;
	int		max;

	best_score = 0xFFFFFF;
	max = (farm->start->links_cnt < farm->end->links_cnt) ?
			farm->start->links_cnt : farm->end->links_cnt;
	if (max == 0 || !(new_paths = generate_group(farm, NULL)))
		return (NULL);
	score = put_instructions2(new_paths, farm->ant_nb, 0);
	if (score < best_score)
	{
		best_score = score;
		selected = new_paths;
	}
	push_flow_to_paths(new_paths);
	ultimate_solver_helper(max, &best_score, farm, &selected);
	return (selected);
}

int		start_end(t_farm *farm)
{
	int		i;
	t_child *childs;

	childs = farm->start->childs;
	while (childs && childs->room != farm->end)
		childs = childs->next;
	if (childs && childs->room == farm->end && (i = 1))
	{
		ft_readline(0, NULL, AFF_AND_FREE);
		ft_putchar('\n');
		while (i <= farm->ant_nb)
		{
			ft_putstr("L");
			ft_putnbr(i);
			ft_putstr("-");
			ft_putstr(farm->end->name);
			if (i++ < farm->ant_nb)
				ft_putstr(" ");
		}
		ft_putstr("\n");
		return (1);
	}
	return (0);
}

int		pick_right_paths(t_farm *farm)
{
	t_paths	*selected;

	if (start_end(farm))
		return (1);
	selected = ultimate_solver(farm);
	if (selected == NULL)
		ft_exit("ERROR");
	ft_readline(0, NULL, AFF_AND_FREE);
	ft_putchar('\n');
	return (put_instructions2(selected, farm->ant_nb, 1));
}
