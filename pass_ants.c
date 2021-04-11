/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:52:39 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:43:18 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

void	print_instr(int a_o_h, char *room_name)
{
	ft_putstr("L");
	ft_putnbr(a_o_h);
	ft_putchar('-');
	ft_putstr(room_name);
	ft_putchar(' ');
}

int		push_ants(t_paths *paths, int mode)
{
	t_child	*child;
	int		ant_on_save;
	int		ant_on_hold;
	int		empty;

	empty = 0;
	child = paths->path;
	ant_on_save = child->room->ant_nb;
	while (child)
	{
		if (child->room->ant_nb != 0)
			empty = 1;
		ant_on_hold = ant_on_save;
		if (child->next)
		{
			ant_on_save = child->next->room->ant_nb;
			if (ant_on_hold != 0 && mode)
				print_instr(ant_on_hold, child->next->room->name);
			child->next->room->ant_nb = ant_on_hold;
		}
		else if (ant_on_hold != 0 && mode)
			print_instr(ant_on_hold, paths->path->room->farm->end->name);
		child = child->next;
	}
	return (empty);
}

void	push_new_ants(t_paths *paths, int *ant)
{
	t_child	*child;

	child = paths->path;
	if (child && child->next)
	{
		if (child->room->farm->ant_nb >= *ant && paths->in_q > 0)
		{
			child->room->ant_nb = *ant;
			(paths->in_q)--;
			*ant += 1;
		}
		else
			child->room->ant_nb = 0;
	}
}

int		move_the_ants(t_paths *paths, int *ant, int mode)
{
	t_paths	*p_paths;
	int		done;
	int		all_pass;

	done = 1;
	p_paths = paths;
	all_pass = 0;
	while (p_paths)
	{
		push_new_ants(p_paths, ant);
		all_pass += push_ants(p_paths, mode);
		p_paths = p_paths->next;
	}
	if (all_pass == 0)
		done = 0;
	return (done);
}

int		pass_ants(t_paths *paths, int mode)
{
	t_paths *p_paths;
	int		inst_nb;
	int		ant;
	int		done;

	done = 1;
	inst_nb = 0;
	ant = 1;
	p_paths = paths;
	while (done)
	{
		done = move_the_ants(p_paths, &ant, mode);
		inst_nb++;
		if (mode)
			ft_putstr("\n");
	}
	return (inst_nb);
}
