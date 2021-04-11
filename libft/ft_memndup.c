/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:31:12 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:31:13 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memndup(size_t size)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (n < size)
		str[n++] = '\0';
	return ((void *)str);
}
