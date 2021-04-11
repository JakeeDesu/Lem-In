/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:31:19 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 07:48:09 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_child	*get_path_copy(t_child *path)
{
	t_child *new_path;
	t_child	*p_child;
	t_child	*p_path;

	new_path = NULL;
	if (path)
	{
		p_path = path;
		new_path = mem_malloc(sizeof(t_child), ALLOCATE);
		new_path->room = path->room;
		new_path->next = NULL;
		p_child = new_path;
		p_path = p_path->next;
		while (p_path)
		{
			p_child->next = mem_malloc(sizeof(t_child), ALLOCATE);
			p_child->next->room = p_path->room;
			p_child = p_child->next;
			p_path = p_path->next;
		}
		p_child->next = NULL;
	}
	return (new_path);
}

t_child	*get_path_copy_plus_helper(t_child **new_path, t_child *path)
{
	t_child	*p_path;
	t_child	*p_child;

	p_path = path;
	*new_path = mem_malloc(sizeof(t_child), ALLOCATE);
	(*new_path)->room = path->room;
	(*new_path)->next = NULL;
	p_child = *new_path;
	p_path = p_path->next;
	while (p_path)
	{
		p_child->next = mem_malloc(sizeof(t_child), ALLOCATE);
		p_child->next->room = p_path->room;
		p_child = p_child->next;
		p_path = p_path->next;
	}
	p_child->next = NULL;
	return (p_child);
}

t_child	*get_path_copy_plus(t_child *path, t_room *room)
{
	t_child *new_path;
	t_child	*p_child;

	new_path = NULL;
	if (path)
		p_child = get_path_copy_plus_helper(&new_path, path);
	if (new_path)
	{
		p_child->next = mem_malloc(sizeof(t_child), ALLOCATE);
		p_child->next->room = room;
		p_child->next->next = NULL;
	}
	else
	{
		new_path = mem_malloc(sizeof(t_child), ALLOCATE);
		new_path->room = room;
		new_path->next = NULL;
	}
	return (new_path);
}
