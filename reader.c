/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:45:13 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:01:49 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

void	ft_add_childs(t_room *first, t_room *second)
{
	t_child *child1;
	t_child *child2;

	child1 = mem_malloc(sizeof(t_child), ALLOCATE);
	child2 = mem_malloc(sizeof(t_child), ALLOCATE);
	first->links_cnt += 1;
	second->links_cnt += 1;
	child1->capacity = 1;
	child2->capacity = 1;
	child1->locked = 0;
	child2->locked = 0;
	child2->room = first;
	child1->room = second;
	child1->next = first->childs;
	first->childs = child1;
	child2->next = second->childs;
	second->childs = child2;
}

int		ft_add_link(t_farm **farm, char *from, char *to)
{
	t_room	*room_tr;
	int		ver;
	t_room	*first;
	t_room	*second;

	room_tr = (*farm)->rooms;
	ver = 0;
	while (room_tr != NULL && ver < 2)
	{
		if (ft_strcmp(from, room_tr->name) == 0)
		{
			ver++;
			first = room_tr;
		}
		if (ft_strcmp(to, room_tr->name) == 0)
		{
			ver++;
			second = room_tr;
		}
		room_tr = room_tr->next;
	}
	if (ver != 2)
		ft_exit("ERROR");
	ft_add_childs(first, second);
	return (0);
}

int		ver_link(char *line, t_farm **farm)
{
	char	**splited;
	size_t	len;

	splited = ft_strsplit1(line, '-', &len);
	if (len != 2)
		ft_exit("ERROR");
	return (ft_add_link(farm, splited[0], splited[1]));
}

int		get_farm_links(char **line, t_farm **farm)
{
	if (**line == 'L' || **line == ' ' || **line == '\t' || **line == '\0')
		ft_exit("ERROR");
	if (**line == '#')
	{
		if (ft_strcmp((*line) + 1, "#start") == 0 ||
			ft_strcmp((*line) + 1, "#end") == 0)
			ft_exit("ERROR");
		return (0);
	}
	return (ver_link(*line, farm));
}

t_farm	*get_the_farm(void)
{
	int		fd;
	char	*line;
	t_farm	*farm;
	int		option;
	int		count;

	option = 0;
	farm = init_farm();
	fd = 0;
	ft_readline(0, NULL, INIT);
	get_ant_number(fd, &farm);
	while (ft_readline(fd, &line, READ) == 1)
	{
		if ((count = get_farm_struct(&line, &option, &farm, fd)) == -1)
			break ;
		farm->room_nb = farm->room_nb + count;
	}
	if (farm->start == NULL || farm->end == NULL)
		ft_exit("ERROR");
	while (get_farm_links(&line, &farm) != -1 &&
		ft_readline(fd, &line, READ) == 1)
		;
	return (farm);
}
