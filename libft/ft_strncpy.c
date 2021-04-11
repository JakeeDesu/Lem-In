/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:15:28 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/08 09:32:29 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t l;

	l = ft_strlen(src);
	if (l > len)
		l = len;
	i = 0;
	while (i < l)
	{
		dst[i] = src[i];
		i++;
	}
	while (l < len)
		dst[l++] = '\0';
	return (dst);
}
