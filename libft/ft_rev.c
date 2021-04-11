/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:27:31 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:27:33 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rev(char *str)
{
	size_t	i;
	size_t	n;
	char	*s;

	i = 0;
	n = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
		if (!(s = (char	*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		while (i > 0)
			s[n++] = str[(i--) - 1];
		s[n] = '\0';
		return (s);
	}
	return (NULL);
}
