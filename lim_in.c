/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lim_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:50:20 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 09:16:28 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

int		main(void)
{
	t_farm	*farm;

	mem_malloc(0, INIT);
	farm = get_the_farm();
	pick_right_paths(farm);
	mem_malloc(0, WIPE);
	return (0);
}
