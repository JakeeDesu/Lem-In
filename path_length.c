/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:54:33 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:43:15 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

int		path_length(t_child *childs)
{
	int cnt;

	cnt = 0;
	while (childs)
	{
		cnt++;
		childs = childs->next;
	}
	return (cnt);
}
