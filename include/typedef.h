/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 05:04:14 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/22 02:40:25 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

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
	int				discovered;
	t_links			*links;
	struct s_room	*next;
}					t_room;

typedef struct      s_queue
{
    t_room          *room;
    struct s_queue  *next;
}                   t_queue;

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

#endif