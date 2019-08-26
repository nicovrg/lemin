/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 05:04:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/27 00:22:59 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "typedef.h"

/*
** ==================== general ====================
** error.c 
** free_all.c
*/

int			error_of_status(int *status);
int			error_while_gnl(char **line, char *error_msg);
int			error_with_status(char **line, t_room **rooms);
int			error_msg(char *error_msg);

int			free_all(t_room **rooms, char ***tab, t_path **paths, int var);
int			free_queue(t_queue **queue);
int			free_paths(t_path **paths, int var);
int			free_one_path(t_path **paths, t_path **current);
int			del_room_in_path(t_path **current);

/*
** ==================== algo ====================
** lemin.c
** bfs.c
** queue.c
** find_rooms.c
*/

int			fill_path(int nb_path, t_queue **find_end, t_path **paths);
int			lemin(t_room **room, t_queue **queue, t_path **paths);

int			init_bfs(t_room **room, t_queue **queue, t_room **current_room);
int			bfs(t_room **room, t_queue **queue, t_room **current_room, t_room **room_to_push);

int			init_queue(t_queue **queue, t_room **room);
int			push_queue(t_queue **queue, t_room **room, char *prev_name);
t_room*		pop_queue(t_queue **queue);


t_room*		find_start_room(t_room **room);
t_room*		find_room(t_room **room, char *name);

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

int			check_lines(t_room **rooms, int	*nb_ant, char ***tab);

int			check_map_validity(t_room **rooms);

int			check_coords_in_room(char *line);
int			is_tubes(t_room **rooms, char *line, int *status);

int			fill_rooms(t_room **rooms, t_norme *norme);

int			fill_tubes(t_room **rooms, char *line);

int			room_is_banned(char *name, t_ban **list);
int			room_is_passed(t_path **current, char *name);

/*
** ==================== trash ====================
** check_paths.c
** fill_paths.c
*/

int			parse_paths(t_room **rooms, t_path **current, char *name, t_ban **list);
int			check_paths(t_room **rooms, t_path **paths, t_ban **list);

t_links		*add_room_in_path(t_links **buf, char *name);
t_path		*init_paths(t_path **paths, int i, char *name);
int			fill_banned_rooms(t_ban **list, char *name);

#endif