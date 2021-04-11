/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:11:58 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/14 17:25:07 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *ne, size_t len)
{
	size_t	i;
	char	*c;

	c = (char *)h;
	if (ft_strlen(ne) == 0)
		return (c);
	i = 0;
	while (i < len)
	{
		if (ft_strncmp(h + i, ne,
					ft_strlen(ne)) == 0 && i + ft_strlen(ne) <= len)
			return (c + i);
		i++;
	}
	return (NULL);
}
