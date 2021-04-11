/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstidel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:27:17 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/17 16:33:42 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstidel(t_list **lst, size_t n)
{
	size_t	i;
	t_list	*k;
	t_list	*p;

	i = 0;
	k = *lst;
	while ((k) && i < n - 1)
	{
		p = k;
		k = k->next;
		i++;
	}
	p->next = k->next;
	free(k->content);
	k->content_size = 0;
	k->next = NULL;
	free(k);
}
