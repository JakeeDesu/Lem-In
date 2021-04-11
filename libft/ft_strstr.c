/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 00:00:15 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/10 13:12:59 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *ne)
{
	int		i;
	char	*c;

	c = (char *)h;
	if (ft_strlen(ne) == 0)
		return (c);
	i = 0;
	while (h[i] != '\0')
	{
		if (ft_strncmp(h + i, ne,
					ft_strlen(ne)) == 0)
			return (c + i);
		i++;
	}
	return (NULL);
}
