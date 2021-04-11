/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:45:13 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:01:56 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

int		ver_max_int(int s, size_t number)
{
	if (s < 0 && number > 2147483648)
		return (1);
	if (s > 0 && number > 2147483647)
		return (1);
	return (0);
}

int		ver_int(char *number)
{
	int		i;
	size_t	ret;
	int		s;
	int		ver;

	i = 0;
	ret = 0;
	s = 1;
	ver = 0;
	if (number[i] == '-' || number[i] == '+')
	{
		i++;
		ver++;
		s = (number[i] == '+') - (number[i] == '-') - 1;
	}
	while (number[i] != '\0' && ft_isdigit(number[i]))
		ret = ret * 10 + (number[i++] - '0');
	if (i - ver == 0 || number[i] != '\0' || ver_max_int(s, ret))
		ft_exit("ERROR");
	return (s * ret);
}

void	get_ant_number(int fd, t_farm **farm)
{
	char *line;

	ft_readline(fd, &line, READ) != 1 ? ft_exit("ERROR") : 0;
	while (line[0] == '#')
	{
		if (ft_strcmp(line + 1, "#start") == 0 ||
			ft_strcmp(line + 1, "#end") == 0)
			ft_exit("ERROR");
		ft_readline(fd, &line, READ) != 1 ? ft_exit("ERROR") : 0;
	}
	(*farm)->ant_nb = ver_int(line);
	if ((*farm)->ant_nb <= 0)
		ft_exit("ERROR");
}
