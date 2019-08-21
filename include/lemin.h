/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:52:32 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/21 01:01:36 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "ft_printf.h"

# define ERR_PARSE_1 "error in check_lines - fail to append room to room list"

typedef struct		s_links
{
	char			*room;
	struct s_links	*next;
}					t_links;

typedef struct		s_path
{
	int				path;
	t_links			*links;
	struct s_path	*next;
}					t_path;

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	t_links			*links;
	struct s_room	*next;
}					t_room;

typedef struct		s_norme
{
	char			*line;
	int				count;
	int				var;
	int				start;
	int				end;
}					t_norme;

typedef struct		s_ban
{
	char			*name;
	struct s_ban	*next;
}					t_ban;

int					check_coords_in_room(char *line);
int					is_tubes(t_room **rooms, char *line, int *status);
int					check_is_tubes(t_room **rooms, char *line, int *status);
int					check_map_validity(t_room **rooms);
int					check_lines(t_room **rooms, int *nb_ant, char ***tab);
int					check_paths(t_room **rooms, t_path **paths, t_ban **list);
int					del_room_in_path(t_path **current);
int					error_of_status(int *status);
int					error_while_gnl(char **line, char *error_msg);
int					error_with_status(char **line, t_room **rooms);
t_links				*add_room_in_path(t_links **buf, char *name);
int					fill_banned_rooms(t_ban **list, char *name);
int					fill_rooms(t_room **rooms, t_norme *norme);
int					fill_tubes(t_room **rooms, char *line);
t_path				*init_paths(t_path **paths, int i, char *name);
int					free_all(t_room **rooms, t_ban **list, t_path **paths, int var);
int					free_paths(t_path **paths, int var);
int					free_one_path(t_path **paths, t_path **current);
int					parse_paths(t_room **rooms, t_path **current, char *name, t_ban **list);
int					room_is_banned(char *name, t_ban **list);
int					room_is_passed(t_path **current, char *name);

#endif
