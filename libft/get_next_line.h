/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:33:46 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:33:51 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define INIT 0
# define READ 1
# define AFF_AND_FREE 2
# define JUST_FREE 3
# define INIT 0
# define ALLOCATE 1
# define WIPE 2

typedef struct			s_mem_list
{
	void				*adress;
	struct s_mem_list	*next;
}						t_mem_list;

#endif
