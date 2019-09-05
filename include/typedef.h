/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 05:04:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/05 23:29:01 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef	struct		s_zelda
{
	char			*name;
	struct s_zelda	*next;
}					t_zelda;

typedef struct		s_links
{
	char			*room;
	int				discovered;
	struct s_links	*next;
}					t_links;

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	int				discovered;
	t_links			*links;
	struct s_room	*next;
}					t_room;

typedef struct		s_path
{
	int				nb_path;
	t_links			*lst_rooms;
	struct s_path	*next;
}					t_path;

typedef struct		s_queue
{
	struct s_queue	*prev_link;
	t_room			*room;
	struct s_queue	*prev;
	struct s_queue	*next;
}					t_queue;

typedef	struct		s_lemin
{
	int				nb_ant;
	char			**tab;
	t_room			*room;
	t_path			*path;
	t_queue 		*queue;
	t_zelda 		*zelda;
}					t_lemin;

typedef struct		s_norme
{
	char			*line;
	int				count;
	int				var;
	int				start;
	int				end;
}					t_norme;

#endif