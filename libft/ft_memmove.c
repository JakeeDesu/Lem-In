/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:29:41 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:29:45 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void *c;

	c = p_malloc(sizeof(unsigned char) * n);
	ft_memcpy(c, src, n);
	ft_memcpy(dst, c, n);
	free(c);
	return (dst);
}
