/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:25:36 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:25:41 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub1(const char *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	if (!(s1 = (char *)mem_malloc(sizeof(char) * (len + 1), ALLOCATE)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[len] = '\0';
	return (s1);
}

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	if (!(s1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[len] = '\0';
	return (s1);
}
