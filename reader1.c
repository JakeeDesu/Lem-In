/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:45:13 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/22 08:56:49 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lim_in.h"

t_farm	*init_farm(void)
{
	t_farm *ret;

	ret = (t_farm *)mem_malloc(sizeof(t_farm), ALLOCATE);
	ret->room_nb = 0;
	ret->rooms = NULL;
	ret->start = NULL;
	ret->end = NULL;
	ret->extended = NULL;
	return (ret);
}

t_room	*ft_new_room(t_farm **farm, char *name, char *x, char *y)
{
	t_room *room;

	room = (t_room *)mem_malloc(sizeof(t_room), ALLOCATE);
	room->visited = 0;
	room->in_flow = 0;
	room->path_id = -1;
	room->in_paths = 0;
	room->links_cnt = 0;
	ver_int(x);
	ver_int(y);
	room->name = name;
	room->farm = *farm;
	room->childs = NULL;
	room->next = NULL;
	return (room);
}

int		ft_add_room(t_farm **farm, char *name, char *x, char *y)
{
	t_room *tracker;

	tracker = (*farm)->rooms;
	while (tracker != NULL && ft_strcmp(tracker->name, name) != 0)
		tracker = tracker->next;
	if (tracker == NULL)
	{
		tracker = (*farm)->rooms;
		(*farm)->rooms = ft_new_room(farm, name, x, y);
		(*farm)->rooms->next = tracker;
		(*farm)->op == 2 ? ((*farm)->start = (*farm)->rooms) : 0;
		(*farm)->op == 3 ? ((*farm)->end = (*farm)->rooms) : 0;
		return (1);
	}
	ft_exit("ERROR");
	return (0);
}

int		ver_room(char *line, t_farm **farm, int op)
{
	char	**splited;
	size_t	len;

	splited = ft_strsplit1(line, ' ', &len);
	if (len != 3)
		return (-1);
	(*farm)->op = op;
	return (ft_add_room(farm, splited[0], splited[1], splited[2]));
}

int		get_farm_struct(char **line, int *option, t_farm **farm, int fd)
{
	int ver_rm;

	if (**line == 'L' || **line == ' ' || **line == '\t' || **line == '\0')
		ft_exit("ERROR");
	if (**line == '#' && *option < 2)
	{
		if (ft_strcmp((*line) + 1, "#start") == 0 &&
			ft_readline(fd, line, READ) == 1 && (*option = 2))
			return (get_farm_struct(line, option, farm, fd));
		if (ft_strcmp((*line) + 1, "#end") == 0 &&
			ft_readline(fd, line, READ) == 1 && (*option = 3))
			return (get_farm_struct(line, option, farm, fd));
		return (0);
	}
	if (*option >= 2)
	{
		ver_rm = ver_room(*line, farm, *option);
		*option = 1;
		if (ver_rm == -1)
			ft_exit("ERROR");
		return (ver_rm);
	}
	return (ver_room(*line, farm, 1));
}
