/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 05:04:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/19 20:04:30 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "typedef.h"

/*
** ==================== general ====================
** error.c
** free_all.c
** debug.c
*/

int			error_of_status(int *status);
int			error_while_gnl(char **line, char *error_msg);
int			error_with_status(char **line, t_lemin *l);
int			error_msg(char *error_msg);

int			free_all(int var, t_lemin *l);
int			free_queue(t_queue **queue);
int			free_paths(t_path **paths);

int			print_rooms(t_lemin *l);
int			print_queue(t_queue **queue);
int			print_paths(t_path **paths);

/*
** ==================== algo ====================
** lemin.c
** bfs.c
** queue.c
** find_rooms.c
** fill_path.c
** test_graph.c
** update_path.c
** count_kchoz.c
** print_render.c
** buffer.c
*/

int			init_lemin(t_lemin *l, t_queue **end, t_room **current,
			t_room **push);
int			lemin(t_lemin *l);

int			init_bfs(t_lemin *l, t_room **current_room);
int			bfs(t_queue **queue_state, t_room **current_room,
			t_room **room_to_push);

int			init_queue(t_lemin *l, t_room **room);
int			push_queue(t_queue **queue, t_room **room_to_push,
			t_links **links, t_links ***tab);
int			push_room(t_room **room_to_push, t_links **tmp_links,
			t_queue **queue_state, t_links ***tab);

t_room		*find_start_room(t_lemin *l);

int			put_links_to_full(t_queue **find_end);

int			update_graph(t_lemin *l);

long		test_graph(t_lemin *l, t_path **updated_path);

int			nb_max_paths(t_lemin *l);
int			count_lst_rooms(t_lst_room **lst_rooms);

int			print_render(t_lemin *l);
int			print_ant(int ant, char *room_name, t_lemin *l);

int			swap_ants(t_lemin *l);
int			move_from_start(t_lemin *l);
int			still_ants_in_path(t_lemin *l);

int			addchar_buff(int print, char char_to_append, t_lemin *l);
int			addnbr_buff(int nb_to_append, t_lemin *l);
int			addstr_buff(char *str_to_append, t_lemin *l);

/*
** ==================== parse ====================
** check_lines.c
** check_map_validity.c
** check_rooms_and_links.c
** fill_paths.c
** fill_rooms.c
** fill_tubes.c
** rooms_visited.c
*/

int			check_lines(t_lemin *l);

int			check_map_validity(t_lemin *l);

int			check_coords_in_room(char *line);
int			is_tubes(t_lemin *l, char *line, int *status);

int			fill_rooms(t_lemin *l, t_parse *parse);

int			fill_tubes(t_lemin *l, char *line);

#endif
