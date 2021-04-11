/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:14:45 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/20 18:14:55 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(char *error)
{
	if (error != NULL)
		ft_putendl_fd(error, 2);
	ft_readline(0, NULL, JUST_FREE);
	mem_malloc(0, WIPE);
	exit(1);
}

void	*p_malloc(size_t size)
{
	void *ret;

	if (!(ret = malloc(size)))
		ft_exit(NULL);
	return (ret);
}
