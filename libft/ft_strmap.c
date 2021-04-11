/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:21:37 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/11 01:46:50 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	l;
	size_t	i;
	char	*s1;

	l = ft_strlen(s);
	if (!(s1 = (char *)malloc(sizeof(char) * l + 1)))
		return (NULL);
	i = 0;
	while (i < l)
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
