/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:00:55 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 09:16:03 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	go(int *i, char **l, int fd)
{
	char buf[BUFF_SIZE + 1];
	char *l1;

	*i = read(fd, buf, BUFF_SIZE);
	buf[*i] = '\0';
	l1 = *l;
	*l = ft_strjoin(*l, buf);
	free(l1);
	while (*i == BUFF_SIZE && !(ft_strchr(buf, '\n')))
	{
		*i = read(fd, buf, BUFF_SIZE);
		buf[*i] = '\0';
		l1 = *l;
		*l = ft_strjoin(*l, buf);
		free(l1);
	}
}

int		ft_return(int i, char **line, char **l)
{
	int		k;
	char	*l1;

	if (i < BUFF_SIZE && !(ft_strchr(*l, '\n')))
	{
		*line = *l;
		if (i == 0 && ft_strcmp(*l, "") == 0)
			return (0);
		*l = NULL;
		return (1);
	}
	else
	{
		k = 0;
		while ((*l)[k] != '\n')
			k++;
		*line = ft_strsub(*l, 0, k);
		l1 = *l;
		*l = ft_strdup((*l + k + 1));
		free(l1);
		return (1);
	}
}

t_list	*ft_add(int fd, t_list **ll)
{
	char	**l;
	t_list	*k;

	k = *ll;
	while (k != NULL)
	{
		l = *((char***)k->content);
		if (fd == ft_atoi(l[0]))
			break ;
		k = k->next;
	}
	if (k == NULL)
	{
		l = (char **)p_malloc(sizeof(char *) * 2);
		l[0] = ft_itoa(fd);
		l[1] = NULL;
		ft_lstadd(ll, ft_lstnew(&l, sizeof(char**)));
		k = *ll;
	}
	return (k);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*ll;
	char			**l;
	int				i;
	t_list			*k;

	if (fd < 0 || !line)
	{
		return (-1);
	}
	k = ft_add(fd, &ll);
	l = *((char***)k->content);
	if (!(l[1]))
		l[1] = ft_strnew(0);
	i = 0;
	if (!ft_strchr(l[1], '\n'))
		go(&i, &(l[1]), fd);
	if (i < 0)
		return (-1);
	return (ft_return(i, line, &(l[1])));
}
