/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:26:04 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:26:05 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	l;
	size_t	i;

	l = ft_strlen(s1);
	if ((s2 = (char *)ft_malloc(sizeof(char) * l + 1, 1)) == NULL)
		return (NULL);
	i = 0;
	while (i <= l)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
