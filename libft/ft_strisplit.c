/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:30:29 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:30:31 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_slrisplit(char *str, size_t n)
{
	char	**s;
	size_t	i;

	if (n >= ft_strlen(str))
		return (NULL);
	s = (char **)p_malloc(sizeof(char *) * 2);
	s[0] = (char *)p_malloc(sizeof(char) * (n + 1));
	s[0][n] = '\0';
	i = 0;
	while (i < n)
	{
		s[1][i] = str[i];
		i++;
	}
	s[2] = (char *)p_malloc(sizeof(char) * (ft_strlen(str) - n + 1));
	while (str[i] != '\0')
	{
		s[1][i - n] = str[i];
		i++;
	}
	s[1][i - n] = '\0';
	return (s);
}
