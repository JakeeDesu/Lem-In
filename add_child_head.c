/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_child_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:09:43 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:48:44 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

void	add_child_head(t_child **childs, t_room *room)
{
	t_child	*c;
	t_child	*n_child;

	if (!(n_child = (t_child*)mem_malloc(sizeof(t_child), ALLOCATE)))
		return ;
	n_child->room = room;
	n_child->next = NULL;
	if (!(*childs))
		*childs = n_child;
	else
	{
		c = *childs;
		*childs = n_child;
		(*childs)->next = c;
	}
}

t_child	*add_child_end(t_child **childs, t_room *room)
{
	t_child	*p_child;
	t_child	*n_child;

	if (childs)
	{
		n_child = (t_child*)mem_malloc(sizeof(t_child), ALLOCATE);
		n_child->room = room;
		n_child->next = NULL;
		p_child = *childs;
		if (p_child)
		{
			while (p_child->next)
				p_child = p_child->next;
			p_child->next = n_child;
		}
		else
			*childs = n_child;
		return (*childs);
	}
	return (NULL);
}
