/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:52:32 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/13 03:31:03 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "ft_printf.h"

# define ERR_PARSE_1 "error in check_lines - fail to reallocate tab"
# define ERR_PARSE_2 "error in check_lines - fail to copy line in tab"
# define ERR_PARSE_3 "error in check_lines - fail to append room to room list"

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

int					check_coords_in_room(char *line);
int					check_is_tubes(t_room **rooms, char *line, int *status);
// int					check_links_in_map(t_room **rooms, int start, char *name, char *prev);
int					check_map_validity(t_room **rooms);
int					check_lines(t_room **rooms, int	*nb_ant);
int					check_paths(t_room **rooms, t_room **paths);
int					error_of_status(int *status);
int					error_while_gnl(char **line, char *error_msg);
int					error_with_status(char **line, t_room **rooms);
int					fill_rooms_list(t_room **rooms, t_norme *norme);
int					fill_tubes_list(t_room **rooms, char *line);
int					free_all(t_room **rooms, int var);

#endif
