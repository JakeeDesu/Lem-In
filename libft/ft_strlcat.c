/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:39:41 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/10 12:56:52 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t l1;
	size_t l2;
	size_t i;

	l1 = ft_strlen(s1);
	if (size <= l1)
	{
		l2 = ft_strlen(s2) + size;
		return (l2);
	}
	else
		l2 = ft_strlen(s2) + l1;
	i = 0;
	while (l1 < size - 1 && s2[i] != '\0')
		s1[l1++] = s2[i++];
	s1[l1] = '\0';
	return (l2);
}
