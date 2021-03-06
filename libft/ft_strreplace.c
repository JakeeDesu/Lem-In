/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:43:13 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/17 19:43:20 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreplace(char *str, char c, char c1)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i++] = c1;
	}
}
