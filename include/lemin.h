/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:52:32 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/06 01:55:19 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

typedef struct		s_links
{
	char			*room;
	struct s_links	*next;
}					t_links;

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
}					t_norme;

int					check_coords_in_room(char *line);
int					check_if_tubes(t_room **rooms, char *line, int *status);
int					check_links_in_map(t_room **rooms, int start, char *name,
					char *prev);
int					check_map_validity(t_room **rooms);
int					checklines(t_room **rooms, char ***tab);
int					error_of_status(int *status);
int					error_while_gnl(char **line);
int					error_with_status(char **line, t_room **rooms);
int					fill_rooms_list(t_room **rooms, char *line, int *var);
int					fill_tubes_list(t_room **rooms, char *line);
int					free_lists(t_room **rooms, char ***tab, int var);

#endif
