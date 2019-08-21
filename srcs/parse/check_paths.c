/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:35:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/21 04:23:00 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		parse_links(t_room **rooms, t_path **current, t_ban **list, t_links **links)
{
	while ((*links))
	{
		while ((*links) && (*links)->room
		&& (room_is_passed(current, (*links)->room)
		|| room_is_banned((*links)->room, list)))
			(*links) = (*links)->next;
		if ((*links) && (*links)->room 
		&& !add_room_in_path(&((*current)->links), (*links)->room))
			return (0);
		if ((*links) && (*links)->room
		&& parse_paths(rooms, current, (*links)->room, list) == 1)
			return (1);
		else if ((*links))
		{
			if (!(fill_banned_rooms(list, (*links)->room)))
				return (0);
			del_room_in_path(current);
		}
		if ((*links))
			(*links) = (*links)->next;
	}
	if (!(*links))
		return (2);
	return (2);
}

/*
** ==================== parse_links ====================
** check if the room is passed or banned
** then add it to the current path
** then call parse_paths in recursive
** if we are in the end of a branch not link to end
** ban the room and delete it from the path
*/

int		parse_paths(t_room **rooms, t_path **current, char *name, t_ban **list)
{
	t_room	*tmp;
	t_links	*links;

	tmp = (*rooms);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			if (tmp->end == 1)
				return (1);
			links = tmp->links;
			return (parse_links(rooms, current, list, &links));
		}
		tmp = tmp->next;
	}
	return (2);
}

/*
** ==================== parse_paths ====================
** send to parse_links a ptr on the actual links and paths
*/

int		check_paths(t_room **rooms, t_path **paths, t_ban **list)
{
	int		j;
	int		nb_path;
	t_room	*tmp;
	t_path	*current;
	t_links	*buf;

	nb_path = 1;
	tmp = (*rooms);
	while (tmp)
	{
		if (tmp->start == 1)
		{
			buf = tmp->links;
			while (buf)
			{
				if (!(current = init_paths(paths, nb_path, tmp->name)))
					return (0);
				if (!add_room_in_path(&(current->links), buf->room))
					return (0);
				j = parse_paths(rooms, &current, buf->room, list);
				if (j == 0)
					return (free_paths(paths, 0));
				if (j == 1)
					nb_path++;
				if (j == 2)
					free_one_path(paths, &current);
				buf = buf->next;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

/*
** ==================== check_paths ====================
** check_paths find paths in the graph
** create a tmp on room and move it to the start room
** init a new path with all links of start room 
** add the first room of each path coming from start room
** call recursively parse_path cf doc above
** if the return of parse_path is 0 (malloc error) - free path and return 0
** if the return of parse_path is 1 - path valid, go check the next path
** if the return of parse_path is 2 - path invalid, free path go check the next path
*/
