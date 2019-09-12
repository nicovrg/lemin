/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 05:04:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/12 02:33:01 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct		s_inpath
{
	struct s_room	*room;
	struct s_inpath	*next;
}					t_inpath;

typedef struct		s_path
{
	struct s_inpath	*lst_rooms;
	struct s_path	*next;
}					t_path;

typedef struct		s_links
{
	int				ant;
	int				full;
	char			*room;
	struct s_room	*coming;
	struct s_links	*same_link;
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

typedef struct		s_queue
{
	t_room			*room;
	t_links			*link;
	struct s_queue	*prev_link;
	struct s_queue	*prev;
	struct s_queue	*next;
}					t_queue;

typedef	struct		s_lemin
{
	long			nb_ant;
	int				max_paths;
	char			**tab;
	t_room			*room;
	t_path			*path;
	t_queue 		*queue;
}					t_lemin;

typedef struct		s_norme
{
	char			*line;
	int				count;
	int				var;
	int				start;
	int				end;
	t_links			*ptr_link;
}					t_norme;

#endif