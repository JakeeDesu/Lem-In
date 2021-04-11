/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:41:08 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/10 13:11:33 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	while (len != 0)
	{
		if (s[len] == c)
			return ((char *)(s + len));
		len--;
	}
	if (s[len] == c)
		return ((char *)s);
	return (NULL);
}
