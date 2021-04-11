/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:27:02 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:27:04 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *s, char c)
{
	size_t nbr;
	size_t i;
	size_t e;

	e = ft_strlen(s);
	if (e != 0)
		e--;
	while (e != 0 && s[e] == c)
		e--;
	if (e == 0)
		return (s[0] != c && s[0] != '\0');
	i = 0;
	nbr = 0;
	while (i < e)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i != e)
			nbr++;
	}
	return (nbr);
}

static size_t	*ft_findnext(const char *s, size_t i, char c)
{
	size_t j;
	size_t *l;

	l = (size_t *)p_malloc(sizeof(size_t) * 2);
	while (s[i] == c && s[i] != '\0')
		i++;
	j = i;
	while (s[j] != c && s[j] != '\0')
		j++;
	if (j != i)
	{
		l[0] = i;
		l[1] = j - i;
	}
	return (l);
}

char			**ft_strsplit1(const char *s, char c, size_t *len)
{
	char	**str;
	size_t	*i;
	size_t	j;
	size_t	i1;

	*len = ft_count(s, c);
	if (!(str = (char **)mem_malloc(sizeof(char *) * (*len + 1), ALLOCATE)))
		return (NULL);
	i1 = 0;
	j = 0;
	while (j < *len)
	{
		i = ft_findnext(s, i1, c);
		str[j] = ft_strsub1(s, ((unsigned int *)i)[0], i[1]);
		i1 = i[0] + i[1];
		j++;
		free(i);
	}
	str[j] = NULL;
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	size_t	*i;
	size_t	j;
	size_t	i1;
	size_t	len;

	len = ft_count(s, c);
	if (!(str = (char **)p_malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i1 = 0;
	j = 0;
	while (j < len)
	{
		i = ft_findnext(s, i1, c);
		str[j] = ft_strsub(s, ((unsigned int *)i)[0], i[1]);
		i1 = i[0] + i[1];
		j++;
		free(i);
	}
	str[j] = NULL;
	return (str);
}
