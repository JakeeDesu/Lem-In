/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:28:53 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:28:55 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*l;

	if (!(l = malloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		l->content = NULL;
		l->content_size = 0;
		l->next = NULL;
	}
	else
	{
		if (!(l->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(l->content, content, content_size);
		l->content_size = content_size;
		l->next = NULL;
	}
	return (l);
}
