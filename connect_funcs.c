/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:13:21 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:48:37 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_child		*add_child(t_child **childs, t_room *room)
{
	t_child	*c;
	t_child	*n_child;

	if (!(n_child = (t_child*)mem_malloc(sizeof(t_child), ALLOCATE)))
		return (NULL);
	n_child->capacity = 1;
	n_child->locked = 0;
	n_child->room = room;
	n_child->next = NULL;
	if (childs)
	{
		if (!(*childs))
			*childs = n_child;
		else
		{
			c = *childs;
			while (c->next)
				c = c->next;
			c->next = n_child;
		}
	}
	return (n_child);
}
