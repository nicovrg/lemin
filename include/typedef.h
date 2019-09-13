/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 05:04:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/13 07:33:22 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct			s_lst_room
{
	struct s_room		*room;
	struct s_lst_room	*next;
}						t_lst_room;

typedef struct			s_path
{
	struct s_lst_room	*lst_rooms;
	struct s_path		*next;
}						t_path;

typedef struct			s_links
{
	int					ant;
	int					full;
	char				*room;
	struct s_room		*coming;
	struct s_links		*same_link;
	struct s_links		*next;
}						t_links;

typedef struct			s_room
{
	char				*name;
	int					start;
	int					end;
	struct s_links		*links;
	struct s_room		*next;
}						t_room;

typedef struct			s_queue
{
	struct s_room		*room;
	struct s_links		*link;
	struct s_queue		*prev_link;
	struct s_queue		*prev;
	struct s_queue		*next;
}						t_queue;

typedef	struct			s_lemin
{
	int					max_paths;
	long				nb_ant;
	long				nb_stock;
	char				**tab;
	struct s_room		*room;
	struct s_path		*path;
	struct s_queue 		*queue;
}						t_lemin;

typedef struct			s_norme
{
	char				*line;
	int					count;
	int					var;
	int					start;
	int					end;
	struct s_links		*ptr_link;
}						t_norme;

#endif