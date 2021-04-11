/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:05:10 by rnbou             #+#    #+#             */
/*   Updated: 2020/02/20 18:05:20 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mem_list	*new_mem_list(void *adress)
{
	t_mem_list *ret;

	ret = p_malloc(sizeof(t_mem_list));
	ret->next = NULL;
	ret->adress = adress;
	return (ret);
}

void		ft_just_free(t_mem_list *mem_arch)
{
	t_mem_list *tracker;

	tracker = mem_arch;
	while (mem_arch != NULL)
	{
		tracker = mem_arch->next;
		free(mem_arch->adress);
		free(mem_arch);
		mem_arch = tracker;
	}
}

void		ft_aff_and_free(t_mem_list *mem_arch)
{
	if (mem_arch == NULL)
		return ;
	else
	{
		ft_aff_and_free(mem_arch->next);
		ft_putendl(mem_arch->adress);
		free(mem_arch->adress);
		free(mem_arch);
	}
}

int			ft_readline(int fd, char **line, int option)
{
	static t_mem_list	*mem_arch;
	t_mem_list			*mem_holder;
	int					ret;

	if (option == INIT)
		mem_arch = NULL;
	else if (option == READ)
	{
		ret = get_next_line(fd, line);
		if (ret > 0)
		{
			mem_holder = new_mem_list(*line);
			mem_holder->next = mem_arch;
			mem_arch = mem_holder;
		}
		return (ret);
	}
	else if (option == AFF_AND_FREE)
		ft_aff_and_free(mem_arch);
	else if (option == JUST_FREE)
		ft_just_free(mem_arch);
	return (0);
}

void		*mem_malloc(size_t size, int option)
{
	static t_mem_list	*mem_arch;
	t_mem_list			*mem_holder;

	mem_holder = NULL;
	if (option == INIT)
		mem_arch = NULL;
	else if (option == ALLOCATE)
	{
		mem_holder = p_malloc(sizeof(t_mem_list));
		mem_holder->adress = p_malloc(size);
		mem_holder->next = mem_arch;
		mem_arch = mem_holder;
		return (mem_arch->adress);
	}
	else if (option == WIPE)
		ft_just_free(mem_arch);
	return (0);
}
