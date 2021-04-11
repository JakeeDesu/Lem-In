/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:55:37 by rnbou             #+#    #+#             */
/*   Updated: 2019/07/21 23:23:23 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_exit_p(t_list **list)
{
	ft_lstdel(list, free);
	list = NULL;
	exit(EXIT_FAILURE);
}

void	*ft_malloc(size_t size, int option)
{
	void			*ret;
	static	t_list	*list;

	ret = NULL;
	if (option == 0)
		list = NULL;
	else if (option == 1)
	{
		if ((ret = malloc(size)) == NULL)
			ft_exit_p(&list);
		if (list == NULL)
			list = ft_lstnew(ret, size);
		else
			ft_lstadd(&list, ft_lstnew(ret, size));
	}
	else
	{
		ft_lstdel(&list, free);
		list = NULL;
	}
	return (ret);
}
