/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lim_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 23:50:34 by hmhindat          #+#    #+#             */
/*   Updated: 2020/02/22 09:16:49 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_LIM_IN_H
# define H_LIM_IN_H
# include "libft/libft.h"

typedef	struct s_farm		t_farm;
typedef struct s_room		t_room;
typedef struct s_child		t_child;
typedef struct s_paths		t_paths;
typedef	struct s_queue		t_queue;

struct			s_queue
{
	t_child		*crossed_paths;
	t_child		*node_list;
	t_child		*last_node;
	t_queue		*end_q;
	t_queue		*prev;
	t_queue		*next;
};

struct			s_paths
{
	int			path_nb;
	int			path_id;
	int			in_q;
	int			in_queue;
	int			length;
	int			length_v;
	t_child		*path;
	t_paths		*next;
};

struct			s_farm
{
	int			room_nb;
	int			ant_nb;
	t_room		*rooms;
	t_room		*start;
	t_room		*end;
	t_child		*extended;
	int			op;
};

struct			s_room
{
	int			ant_nb;
	int			visited;
	int			in_paths;
	int			in_flow;
	int			path_id;
	int			links_cnt;
	char		*name;
	t_farm		*farm;
	t_child		*childs;
	t_room		*next;
};

struct			s_child
{
	int			capacity;
	int			locked;
	t_room		*room;
	t_child		*next;
};

t_farm			*get_the_farm(void);
void			clear_flow(t_farm *farm);
t_child			*add_child(t_child **childs, t_room *room);
void			add_child_head(t_child **childs, t_room *room);
t_child			*add_child_end(t_child **childs, t_room *room);
int				path_length(t_child *childs);
t_farm			*get_the_farm(void);
void			prepare_q(t_paths *paths, int ant_nb);
int				pass_ants(t_paths *paths, int mode);
int				put_instructions2(t_paths *paths, int ant_nb, int mode);
t_paths			*add_paths(t_child *n_path, int in_paths, int path_id);
void			add_path(t_paths **paths_holder, t_child *n_path, int in_paths);
int				pick_right_paths(t_farm *farm);
t_queue			*get_last_q(t_queue *queue_list);
t_queue			*head_q(t_queue **queue_list, t_child *node_list,
						t_child *last_node);
t_queue			*end_q(t_queue **queue_list, t_child *node_list,
						t_child *last_node);
t_child			*delete_q(t_queue **queue_list);
t_child			*launch_bfs(t_farm *farm);
t_child			*launch_maximizer(t_farm *farm);
t_queue			*init_queue(t_room *start);
t_queue			*extend_first_path(t_queue **queue_list, t_child **path,
									t_child **visited_list);
t_queue			*extend_first_path2(t_queue **queue_list, t_child **path);
t_child			*get_path_copy(t_child *path);
t_child			*get_path_copy_plus(t_child *path, t_room *room);
void			enqueue_paths(t_queue **queue_list, t_queue *extended_paths);
void			clear_in_paths(t_paths *paths);
t_paths			*generate_group(t_farm *farm, t_child *ignored_path);
t_paths			*follow_flow(t_farm *farm);
void			push_flow(t_child *child);
void			push_flow_to_paths(t_paths *paths);
void			clear_flow(t_farm *farm);
void			push_flow(t_child *child);
t_child			*go_with_flow2(t_child *node, t_child *childs);
int				check_if_crossed(t_queue *queue, int path_id);
t_farm			*init_farm(void);
t_room			*ft_new_room(t_farm **farm, char *name, char *x, char *y);
int				ft_add_room(t_farm **farm, char *name, char *x, char *y);
int				ver_room(char *line, t_farm **farm, int op);
int				get_farm_struct(char **line, int *option,
								t_farm **farm, int fd);
int				ver_max_int(int s, size_t number);
int				ver_int(char *number);
void			get_ant_number(int fd, t_farm **farm);
#endif
