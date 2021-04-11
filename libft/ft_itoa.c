/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:02:44 by rnbou             #+#    #+#             */
/*   Updated: 2018/10/17 19:50:22 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cnt(int n)
{
	int nbr;

	if (n == 0)
		return (1);
	nbr = 0;
	while (n != 0)
	{
		n = n / 10;
		nbr++;
	}
	return (nbr);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				l;
	int				i;
	unsigned int	k;

	i = 1 + 1 * (n < 0);
	if (n < 0)
		k = -1 * n;
	else
		k = n;
	l = ft_cnt(k);
	str = (char *)malloc(sizeof(char) * (l + i));
	str[l-- + i - 1] = '\0';
	str[l-- + i - 1] = '0' + k % 10;
	k = k / 10;
	while (k != 0)
	{
		str[l-- + i - 1] = '0' + k % 10;
		k = k / 10;
	}
	if (i == 2)
		str[l + i - 1] = '-';
	return (str);
}
