/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:06:24 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/17 16:43:00 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **lst, t_list *ins, size_t n)
{
	size_t	i;
	t_list	*k;

	i = 0;
	k = *lst;
	while ((k) && i < n - 1)
	{
		k = k->next;
		i++;
	}
	ins->next = k->next;
	k->next = ins;
}
