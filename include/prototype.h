/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 05:04:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/17 04:41:50 by qgirard          ###   ########.fr       */
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
*/
int			init_lemin(t_lemin *l, t_queue **end, t_room **current, t_room **push);
int			lemin(t_lemin *l);

int			init_bfs(t_lemin *l, t_room **current_room);
int			bfs(t_queue **queue_state, t_room **current_room, t_room **room_to_push);

int			init_queue(t_lemin *l, t_room **room);
int			push_queue(t_queue **queue, t_room **room_to_push, t_links **links);

t_room*		find_start_room(t_lemin *l);

int			put_links_to_full(t_queue **find_end);

int			update_graph(t_lemin *l);

long		test_graph(t_lemin *l, t_path **updated_path);

int			nb_max_paths(t_lemin *l);

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


/*
** ==================== trash ====================
** check_paths.c
** fill_paths.c
*/

/*
** int			parse_paths(t_room **rooms, t_path **current, char *name, t_ban **list);
** int			check_paths(t_room **rooms, t_path **paths, t_ban **list);
** int			fill_banned_rooms(t_ban **list, char *name);
** int			room_is_banned(char *name, t_ban **list);
** int			room_is_passed(t_path **current, char *name);
** 
** t_links		*add_room_in_path(t_links **buf, char *name);
** t_path		*init_paths(t_path **paths, int i, char *name);
** 
** t_room*		pop_queue(t_lemin *l);
*/

#endif
