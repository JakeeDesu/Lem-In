/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_instructions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:44:15 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:43:07 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

int		put_instructions2(t_paths *paths, int ant_nb, int mode)
{
	int		inst_nb;
	t_paths	*p_paths;

	p_paths = paths;
	inst_nb = 0;
	prepare_q(paths, ant_nb);
	inst_nb = pass_ants(p_paths, mode);
	return (inst_nb);
}
